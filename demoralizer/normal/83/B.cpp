#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

const int N=1e5+5;

int a[N];
vector<int> v;

void solve(){
	int n,k;
	cin>>n>>k;
	int s=0;
	rep(i,0,n){
		cin>>a[i];
		v.pb(a[i]);
		s+=a[i];
	}
	if(s<k){
		cout<<-1;
		return;
	}
	sort(all(v));
	int lazy=0,rem=n,ans=0;
	
	for(int x:v){
		int y=x-lazy;
		if(y==0){
			rem--;
			continue;
		}
		if(ans+rem*y<=k){
			ans+=rem*y;
			lazy+=y;
			rem--;
		}
		else{
			int z=(k-ans)/rem;
			
			lazy+=z;
			ans+=z*rem;
			break;
		}
	}
	k-=ans;
	deque<int> d;
	rep(i,0,n){
		a[i]-=lazy;
		if(a[i]>0)d.pb(i+1);
	}
	
	rep(i,0,k){
		int x=d.front();
		d.ppf();
		if(a[x-1]>1)d.pb(x);
	}
	
	rep(i,0,sz(d)){
		cout<<d[i]<<" ";
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