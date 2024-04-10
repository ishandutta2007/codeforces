#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
// #define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

pii p[280];
int a[300005][9];
void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,n){
		rep(j,0,m){
			cin>>a[i][j];
		}
	}
	int r=1<<m;
	rep(i,0,r){
		p[i]={-1,-1};
		rep(j,0,n){
			int mn=M;
			rep(k,0,m){
				if(i&(1<<k))mn=min(mn,a[j][k]);
			}
			if(p[i].fr==-1 || p[i].fr<mn)p[i]={mn,j};
		}
		// cout<<i<<" "<<p[i]<<"\n";
	}
	pair<int, pii> ans={-1,{-1,-1}};
	rep(i,0,n){
		rep(j,0,m){
			int bm=0;
			rep(k,0,m){
				if(a[i][k]<a[i][j]){
					bm|=1<<k;
				}
			}
				// cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
			if(p[bm].fr>=a[i][j]){
				if(ans.fr<a[i][j]){
					ans={a[i][j],{i,p[bm].sc}};
				}
			}
		}
	}
	
	cout<<ans.sc.fr+1<<" "<<ans.sc.sc+1<<"\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}