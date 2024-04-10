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

const int N=0;


int z,o;

int n;
int fr;

bool check(int L,int m){
	cout<<"? ";
	rep(i,0,L){
		cout<<z;
	}
	rep(i,L,m+1){
		cout<<o;
	}
	rep(i,m+1,n){
		cout<<z;
	}
	cout<<endl;
	int sc;
	cin>>sc;
	sc=n-sc;
	return (m-L+1+sc-fr);
}

void solve(){
	cin>>n;
	
	cout<<"? ";
	rep(i,0,n){
		cout<<0;
	}
	cout<<endl;
	cin>>fr;
	fr=n-fr;
	
	int tmp;
	cout<<"? 1";
	rep(i,1,n){
		cout<<0;
	}
	cout<<endl;
	cin>>tmp;
	tmp=n-tmp;
	
	if(tmp > fr){
		z=1;
		o=0;
		fr=n-fr;
	}
	else{
		o=1;
		z=0;
	}
	
	int L=0,U=n-1;
	while(L<U){
		int m=(L+U)/2;
		if(check(L,m)){
			U=m;
		}
		else{
			L=m+1;
		}
	}
	
	if(z==0)cout<<"! 1"<<" "<<L+1<<endl;
	else cout<<"! "<<L+1<<" 1"<<endl;
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