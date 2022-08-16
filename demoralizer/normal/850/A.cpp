#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e3+5;

int a[N];
int b[N];
int c[N];
int d[N];
int e[N];

int x=N-2;
int y=N-3;

int dot(){
	return a[x]*a[y]+b[x]*b[y]+c[x]*c[y]+d[x]*d[y]+e[x]*e[y];
}

void solve(){
	int n;
	cin>>n;
	if(n>15){
		cout<<0;
		return;
	}
	rep(i,1,n+1){
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
	}
	
	vector<int> ans;
	rep(i,1,n+1){
		bool f=1;
		rep(j,1,n+1){
			if(i==j)continue;
			a[x]=a[j]-a[i];
			b[x]=b[j]-b[i];
			c[x]=c[j]-c[i];
			d[x]=d[j]-d[i];
			e[x]=e[j]-e[i];
			rep(k,j+1,n+1){
				if(i==k)continue;
				a[y]=a[k]-a[i];
				b[y]=b[k]-b[i];
				c[y]=c[k]-c[i];
				d[y]=d[k]-d[i];
				e[y]=e[k]-e[i];
				if(dot() > 0) f=0;
			}
		}
		if(f){
			ans.pb(i);
		}
	}
	cout<<sz(ans)<<"\n";
	for(int x:ans){
		cout<<x<<"\n";
	}
	
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}