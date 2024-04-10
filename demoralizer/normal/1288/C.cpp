#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
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

int N;
int dp1[1005][12];
int dp2[1005][12];
int calc1(int n,int m){
	if(m==0)return 1;
	int &ans=dp1[n][m];
	if(ans!=-1)return ans;
	ans=0;
	rep(i,1,n+1){
		ans+=calc1(i,m-1);
		ans%=M;
	}
	return ans;
}

int calc2(int n,int m){
	if(m==0)return 1;
	int &ans=dp2[n][m];
	if(ans!=-1)return ans;
	ans=0;
	rep(i,n,N+1){
		ans+=calc2(i,m-1);
		ans%=M;
	}
	return ans;
}

void solve(){
	mem1(dp1);
	mem1(dp2);
	int m;
	cin>>N>>m;
	int ans=0;
	rep(i,1,N+1){
		// cout<<calc1(i,m-1)<<" "<<calc2(i,m-1)<<"\n";
		int t=0;
		rep(j,i,N+1){
			t+=calc2(j,m-1);
			t%=M;
		}
		t*=calc1(i,m-1);
		t%=M;
		ans=(t+ans)%M;
		ans%=M;
	}
	cout<<ans;
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