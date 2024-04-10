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

const int N=1e5+5;

int ae[N],be[N],ao[N],bo[N],q[N];

int get(int* k,int l,int r){
	int ans = k[r];
	if(l) ans -= k[l-1];
	return ans;
}

pii dp[N];

void solve(){
	int n,m;
	string s;
	cin>>n>>s>>m;
	int ca=m-m/2,cb=m/2;
	rep(i,0,n){
		if(s[i]=='?'){
			q[i]++;
			continue;
		}
		if(i%2){
			if(s[i]=='a'){
				ao[i]++;
			}
			else{
				bo[i]++;
			}
		}
		else{
			if(s[i]=='a'){
				ae[i]++;
			}
			else{
				be[i]++;
			}
		}
	}
	rep(i,1,n){
		ae[i]+=ae[i-1];
		ao[i]+=ao[i-1];
		be[i]+=be[i-1];
		bo[i]+=bo[i-1];
		q[i]+=q[i-1];
	}
	
	for(int i=n-m;i>=0;i--){
		dp[i] = dp[i+1];
		if(i%2){
			if(get(bo,i,i+m-1) == 0 && get(ae,i,i+m-1) == 0){
				int k = get(q,i,i+m-1);
				amax(dp[i],pii{dp[i+m].fr+1,dp[i+m].sc-k});
			}
		}
		else{
			if(get(ao,i,i+m-1) == 0 && get(be,i,i+m-1) == 0){
				int k = get(q,i,i+m-1);
				amax(dp[i],pii{dp[i+m].fr+1,dp[i+m].sc-k});
			}
		}
	}
	cout<<-dp[0].sc;
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
	//cin>>t;
	while(t--) solve();
	return 0;
}