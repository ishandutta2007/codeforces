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

const long long INF=1e9;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e6+5;

int n;
string s;
int dp[N][2];

int calc(int x,int y){
	if(x==n){
		if(y==0)return 0;
		else return INF;
	}
	int &ans=dp[x][y];
	if(ans!=-1)return ans;
	if(y==0){
		if(s[x]=='1')ans=1+calc(x+1,y);
		else{
			ans=calc(x+1,y);
			amin(ans,1+calc(x+1,!y));
		}
	}
	else{
		if(s[x]=='0')ans=1+calc(x+1,y);
		else{
			ans=calc(x+1,y);
			amin(ans,1+calc(x+1,!y));
		}
	}
	return ans;
}

void solve(){
	cin>>s;
	s='0'+s;
	n=sz(s);
	mem1(dp);
	cout<<calc(0,0);
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