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

int T,N,a,b;
vpi V;
vi A;

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		V.clear();A.clear();
		for (int i=1;i<=N;++i){
			cin>>a;
			if(SZ(V)==0||V.back().f != a){
				V.pb(a,1);
			}else ++V.back().s;
		}
		for (int i=1;i<SZ(V);++i)V[i].s += V[i-1].s;
		A.pb(0);
		for (auto i :V)A.pb(i.s);
		A.pb(INF);
		int tot = *(--ub(ALL(A),N/2));
		// cout<<tot<<'\n';
		int g = A[1];
		if (g>=tot){cout<<"0 0 0\n";continue;}
		int t = *ub(ALL(A),g*2);
		if (g>=tot-t){cout<<"0 0 0\n";continue;}
		if (g>=t)assert(0);
		cout<<g<<' '<<t-g<<' '<<tot-t<<'\n';
	}
}