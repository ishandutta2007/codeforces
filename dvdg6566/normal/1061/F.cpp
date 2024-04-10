#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 1600;
const bool db = 0;
int N,K;
int blk[MAXN];
vi tp;
int mm[MAXN];
int done[MAXN];

int rand_node(){
	int x = rand()%N+1;
	while (blk[x])x = rand()%N+1;
	return x;
}

vi V[MAXN];
int dfs_b, dfs_c;

int dfs(int x, int p, int flag){
	if (x == dfs_b)flag=1;
	if (flag == 1 && x == dfs_c){
		return 1;
	}
	int res=0;
	for (auto v:V[x])if(v!=p){
		res = res | dfs(v,x,flag);
	}
	return res;
}

int query(int a, int b, int c){
	dfs_c=c;dfs_b=b;
	// cout<<"Query "<<a<<' '<<b<<' '<<c<<' '<<dfs(a,-1,0)<<'\n';
	if(db)return dfs(a,-1,0);
	cout<<"? "<<a<<' '<<b<<' '<<c<<endl;
	string S;
	cin>>S;
	if(S=="Yes")return 1;
	return 0;
}

int sort_a,sort_b;
bool cmp(int a, int b){
	if (query(a,b,sort_b))return 1;
	return 0;
}

int main(){
	cin>>N>>K;
	if (db){
		for (int i=1;i<N;++i){
			int a,b;
			cin>>a>>b;
			V[a].pb(b); V[b].pb(a);
		}
	}
	int layers = 1;
	int used = 1;
	mm[1]=1;
	while (used < N){
		layers++;
		used = used*K+1;
		mm[used] = layers;
		// cout<<"Used "<<used<<' '<<layers<<'\n';
	}
	int tar_len = 2*layers-1;
	// cerr<<"Hello\n";
	assert(used == N);
	srand(9312745);
	int fst = rand_node(); blk[fst] = 1;
	int snd = rand_node(); blk[snd]=1;

	for (int i=1;i<=N;++i)if(!blk[i]){
		if (query(i,fst,snd))tp.pb(i);
	}
	int sz=SZ(tp);	
	if (((N - SZ(tp)-1) * K + 1) == N){
		cout<<"! "<<fst<<flush;
		return 0;
	}
	// cout<<sz<<'\n';
	if (SZ(tp)*2+1 >= N){
		for (int i=1;i<=N;++i)blk[i]++;
		for (auto i:tp)blk[i]--;
		sz = N-sz;
	}else{
		for (auto i:tp)blk[i]=1;
		--blk[snd];
	}
	// cout<<"Root "<<fst<<'\n';
	++sz;
	int lvl=mm[sz];
	for (int i=1;i<=N;++i)done[i] = blk[i];

	for (int x=0;x<1000;++x){
		int cur = rand_node();
		blk[cur]=done[cur]=1;
		// cout<<"Try "<<cur<<'\n';
		int sub = 0;
		for (int i=1;i<=N;++i)if(!done[i]){
			sub += query(i,cur,fst);
		}
		if (sub*2 >= N){done[cur]--;continue;}
		// ++sub;
		int ht = mm[sub];
		// cout<<"Sub "<<sub<<' '<<ht<<'\n';
		deque<int> tmp;
		int along = 1;
		for (int i=1;i<=N;++i)if(!done[i] && i!=cur){
			if (query(cur,i,fst)){
				along++;
				tmp.pb(i);
			}
		}
		if (ht+1==layers){
			cout<<"! "<<cur<<'\n';
			return 0;
		}
		// cout<<lvl + ht + along<<'\n';
		if (lvl + ht + along == tar_len){
			sort_a = fst;
			sort_b = cur;
			sort(ALL(tmp), cmp);
			tmp.push_front(fst);
			tmp.pb(cur);
			// for (auto i :tmp)cout<<i<<' ';cout<<'\n';
			for (int k=1;k<lvl;++k)tmp.push_front(-1);
			cout<<"! "<<tmp[layers-1]<<endl;
			return 0;
		}
		--done[cur];
	}
}