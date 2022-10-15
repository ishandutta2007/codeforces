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
const ll MAXN = 100010;
const int MAXL = 17;
const int BSIZ = 315;

int N,Q;
vi V[MAXN];
int p[MAXN][17];
int depth[MAXN];
typedef pair<pi, int> query;
vector<query> queries;
pi ans[MAXN];
int a,b;
int fw[MAXN];
int pre[MAXN], post[MAXN];
int reversepre[MAXN];

int cmp(query a, query b){
	if (a.f.f/BSIZ == b.f.f/BSIZ)return a.f.s<b.f.s;
	return a.f.f/BSIZ < b.f.f/BSIZ;
}

void update(int x, int v){
	// cout<<"Update "<<x<<' '<<v<<'\n';
	for (;x<=N;x+=x&(-x))fw[x]+=v;
}
int sum(int x){
	int res=0;
	for (;x;x-=x&(-x))res+=fw[x];
	return res;
}
int rng(int x, int y){return sum(y)-sum(x-1);}
void dfs(int x){
	// cout<<x<<' '<<a<<'\n';
	pre[x] = a;
	reversepre[a] = x;
	++a;
	for (auto v:V[x]){
		depth[v]=depth[x]+1;
		dfs(v);
	}
	post[x] = a-1;
}
int fp(int x, int h){
	for (int i=0;i<MAXL;++i)if((1<<i) & h)x=p[x][i];
	return x;
}

int find_item(int a, int b){
	// cout<<"Find between "<<a<<' '<<b<<'\n';
	if (rng(a,b) == 0){return -1;}
	while (b>a){
		int mid = (a+b)/2;
		if (rng(a,mid) == 0)a=mid+1;
		else b=mid;
	}
	assert(rng(a,a)==1);
	// cout<<"Reverse "<<a<<'\n';
	return reversepre[a];
}

int main(){
	cin>>N>>Q;
	memset(p,-1,sizeof(p));
	for (int i=2;i<=N;++i){
		cin>>p[i][0];
		V[p[i][0]].pb(i);
	}
	a=1;
	dfs(1);
	for (int k=1;k<MAXL;++k){
		for (int i=2;i<=N;++i){
			if (p[i][k-1]!=-1)p[i][k] = p[p[i][k-1]][k-1];
		}
	}
	// for (int i=1;i<=N;++i)cout<<pre[i]<<' '<<post[i]<<'\n';
	// return 0;
	for (int i=0;i<Q;++i){
		cin>>a>>b;
		if (a+1==b){
			if (depth[a] > depth[b])ans[i] = mp(b,depth[a]);
			else ans[i] = mp(a,depth[b]);
		}else{
			queries.pb(mp(mp(a,b), i));
		}
	}
	sort(ALL(queries), cmp);
	int l = 1;
	int r = 0;
	for (auto i : queries){
		int tar_l = i.f.f;
		int tar_r = i.f.s;
		int len = tar_r - tar_l +1;
		// cout<<"Try "<<tar_l<<' '<<tar_r<<'\n';
		for (;r<tar_r;++r)update(pre[r+1],1);
		for (;r>tar_r;--r)update(pre[r],-1);
		for (;l<tar_l;++l)update(pre[l],-1);
		for (;l>tar_l;--l)update(pre[l-1],1);
		int lb = 0;
		int ub = depth[tar_l];
		while (ub > lb){
			int mid = (lb+ub)/2;
			int tar = fp(tar_l,mid);
			// cout<<tar<<' '<<rng(pre[tar],post[tar])<<'\n';
			if (rng(pre[tar],post[tar]) >= len)ub=mid;
			else lb = mid+1;
		}
		int lca_depth = lb;
		int lca_res = depth[tar_l] - lb;

		lb = 0;
		ub = depth[tar_l];
		while (ub > lb){
			int mid = (lb+ub)/2;
			int tar = fp(tar_l,mid);
			// cout<<tar<<' '<<rng(pre[tar],post[tar])<<'\n';
			if (rng(pre[tar],post[tar]) >= len-1)ub=mid;
			else lb = mid+1;
		}
		ans[i.s].s = depth[tar_l] - lb;
		++tar_l;
		lb = 0;
		ub = depth[tar_l];
		while (ub > lb){
			int mid = (lb+ub)/2;
			int tar = fp(tar_l,mid);
			// cout<<tar<<' '<<rng(pre[tar],post[tar])<<'\n';
			if (rng(pre[tar],post[tar]) >= len-1)ub=mid;
			else lb = mid+1;
		}
		int res=depth[tar_l] - lb;
		if (res > ans[i.s].s){
			// cout<<"Answer "<<i.s<<' '<<tar_l-1<<'\n';
			ans[i.s] = mp(tar_l-1,res);
			continue;
		}
		--tar_l;

		// Case 1 is if no change
		if (ans[i.s].s == lca_res){
			// Removing someone is useless
			ans[i.s].f = tar_r;
			continue;
		}
		// Case 2 is if got change
		int parent = fp(tar_l,lca_depth);
		int child = fp(tar_l, lca_depth-1);
		update(pre[tar_l],-1);
		// cout<<"Parent "<<parent<<'\n';
		int t = find_item(pre[parent], pre[child]-1);
		if (t == -1)t = find_item(post[child]+1, post[parent]);
		update(pre[tar_l],1);
		// cout<<"Answer "<<i.s<<' '<<t<<'\n';
		ans[i.s].f = t;
	}
	for (int i=0;i<Q;++i)cout<<ans[i].f<<' '<<ans[i].s<<'\n';
}