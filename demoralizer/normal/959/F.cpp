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

int a[N],zval[N];
vector<int> basis, bas[N];
int check(int x){
	for(int y:basis){
		amin(x,x^y);
	}
	return x;
}

int check(int x,int i){
	for(int y:bas[i]){
		amin(x,x^y);
	}
	return x;
}

void solve(){
	int z=1;
	int n,q;
	cin>>n>>q;
	rep(i,1,n+1){
		cin>>a[i];
	}
	
	rep(i,1,n+1){
		int x=check(a[i]);
		if(!x){
			z*=2;
			z%=M;
		}
		else{
			basis.pb(x);
		}
		for(int x:basis){
			bas[i].pb(x);
		}
		zval[i]=z;
	}
	rep(i,0,q){
		int l,x;
		cin>>l>>x;
		x=check(x,l);
		if(x)cout<<0;
		else cout<<zval[l];
		cout<<"\n";
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