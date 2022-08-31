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

#define double long double

void solve(){
	int ans = 2;
	int h,c,t;
	cin>>h>>c>>t;
	
	if(2*t <= (h+c)){
		cout<<"2\n";
		return;
	}
	
	int L = (c-t)/(h+c-2*t);
	
	double a=abs(1.0*(L*h + (L-1)*c)/(2*L-1) - t);
	double b=abs(t - 1.0*((L+1)*h + L*c)/(2*L+1));
	
	int p = 2*L-1,q=2*L+1;
	if(abs((1.0*h+c)/2-t) <= min(a,b)){
		cout<<"2\n";
		return;
	}

	else if(q*(L*h + (L-1)*c) <= 2*t*q*p - ((L+1)*h + L*c)*p){
		cout<<2*L-1;
	}
	else{
		cout<<2*L+1;
	}
	cout<<"\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}
//ypoo