#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 200010
#define MAXL 17
#define INF 1e9

int M[210][210];
int N;
int Q[] = {-1,6,5,4,1,2,3};

bool query(int a, int b){ // returns winner
	if (M[a][b] != -1)return M[a][b];
	cout<<'?'<<' '<<a<<' '<<b<<endl<<flush;
	char c;
	cin >> c;
	// if (Q[a] > Q[b])c = '>';
	// else c = '<';
	M[a][b] = (c=='>');
	M[b][a] = 1-(c=='>');
	return M[a][b];
}

bool cmp(pi a, pi b){
	return query(a.s, b.s);
}

int T;
vpi V;
int done[MAXN];

int kill(int tar){
	int place = 1;
	for (int i=1;i<=2*N;++i)if(i!=tar){
		if (query(i,tar))place++;
	}
	done[place] = tar;
	// cout<<tar<<' '<<place<<'\n';
	return place;
}

vi tmp;

int main(){
	cin >> T;
	while(T--){
		tmp.clear();V.clear();
		cin>>N;
		for (int i=1;i<=2*N;++i)for (int j=1;j<=2*N;++j)M[i][j] = -1;
		for (int i=1;i<=2*N;++i)tmp.pb(i);
		while(SZ(tmp) > 2){
			V.clear();
			for (int i=0;i<SZ(tmp);i+=2)V.pb(tmp[i], tmp[i+1]);

			for (auto &i:V){
				if (!query(i.f, i.s)){
					swap(i.f, i.s);
				}
			}
			sort(ALL(V), cmp);
			// for (auto x : V)cout<<x.f<<' '<<x.s<<'\n';
			tmp.clear();

			if (SZ(V)%2 == 1){
				for (int i=1;i<SZ(V);++i)kill(V[i].s);
				tmp.pb(V[0].f);
				tmp.pb(V[0].s);
				for (int i=1;i<SZ(V);++i)tmp.pb(V[i].f);
			}else{
				for (int i=2;i<SZ(V);++i)kill(V[i].s);
				tmp.pb(V[0].f);
				tmp.pb(V[0].s);
				tmp.pb(V[1].f);
				tmp.pb(V[1].s);
				for (int i=2;i<SZ(V);++i)tmp.pb(V[i].f);
			}
			

			// for (auto i : tmp)cout<<i<<' ';cout<<'\n';
			assert(SZ(tmp)%2 == 0);
			if (SZ(tmp) == 4)break;
			// return 0;
		}
		if (SZ(tmp) == 4){
			// for (auto i : tmp)cout<<i<<' ';cout<<'\n';
			int t = tmp[2];
			if (query(tmp[2], tmp[3]))t = tmp[3];
			if (query(t,tmp[1]))t = tmp[1];
			kill(t);
		}	
		int t = done[N+1];
		assert(t);
		for (int i=1;i<=2*N;++i)if(t!=i&&query(t,i)){
			for (int j=1;j<=2*N;++j)if(i!=j&&j!=t&&query(j,t)){
				query(i,j);
			}
		}
		cout<<'!'<<'\n';
	}
}