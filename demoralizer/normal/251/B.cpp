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

const int N=105;

int n,k;
int p[N];
int tmp[N];
int q[N];
int s[N];
int S[N];

void apply(){
	rep(i,1,n+1){
		tmp[i]=p[q[i]];
	}
	rep(i,1,n+1){
		p[i]=tmp[i];
	}
}

bool check(){
	rep(i,1,n+1){
		if(s[i]!=p[i])return 0;
	}
	return 1;
}

void invper(){
	rep(i,1,n+1){
		tmp[q[i]]=i;
	}
	rep(i,1,n+1){
		q[i]=tmp[i];
	}
}

void solve(){
	cin>>n>>k;
	int cnt,cnt2;
	
	
	rep(i,1,n+1){
		cin>>q[i];
		p[i]=i;
	}
	rep(i,1,n+1){
		cin>>s[i];S[i]=s[i];
	}
	cnt=0;
	while(!check() && cnt<101){
		cnt++;
		apply();
	}
	rep(i,1,n+1){
		s[i]=i;
	}
	cnt2=0;
	while(!check() && cnt2<2){
		cnt2++;
		apply();
	}
	
	if(!((cnt^k)&1)){
		if(k==cnt || (k>cnt && cnt+cnt2>2)){
			cout<<"YES";
			return;
		}
	}
	
	invper();
	
	rep(i,1,n+1){
		p[i]=i;s[i]=S[i];
	}
	cnt=0;
	while(!check() && cnt<101){
		cnt++;
		apply();
	}
	rep(i,1,n+1){
		s[i]=i;
	}
	cnt2=0;
	while(!check() && cnt2<2){
		cnt2++;
		apply();
	}
	
	if(!((cnt^k)&1)){
		if(k==cnt || (k>cnt && cnt+cnt2>2)){
			cout<<"YES";
			return;
		}
	}
	
	cout<<"NO";
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