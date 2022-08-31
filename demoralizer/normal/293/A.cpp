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

const int N=0;



void solve(){
	int n;
	string s,t;
	cin>>n>>s>>t;
	int a=0,b=0,sca=0,scb=0;
	rep(i,0,2*n){
		if(s[i]=='1' && t[i]=='1')a++;
		if(s[i]=='0' && t[i]=='1')b++;
		if(s[i]=='1' && t[i]=='0')b++;
		if(s[i]=='1')sca++;
		if(t[i]=='1')scb++;
	}
	sca+=(a+1)/2*2;
	scb+=(a/2)*2;
	if(a&1){
		scb+=(b+1)/2;
		sca+=(b/2);
	}
	else{
		scb+=(b/2);
		sca+=(b+1)/2;
	}
	if(sca==scb)cout<<"Draw";
	else if(sca>scb)cout<<"First";
	else cout<<"Second";
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