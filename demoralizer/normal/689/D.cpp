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

#define maxn 400005
#define max_logn 20
struct SparseMin{
    int log[maxn];
    int dp[max_logn][maxn];
    SparseMin(){
        log[1] = 0;
        for (int i = 2; i < maxn; i++)
            log[i] = log[i/2] + 1;
    }
    void build(vector<int> b)
    {
        int n=b.size();
        for (int i = 0; i < n; ++i){
            dp[0][i]=b[i];
        }
        for (int j = 1; j < max_logn; j++)
            for (int i = 0; i + (1 << j) < maxn; i++)
                dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
    }
    int query(int l,int r)
    {
        if(l>r)return M;
        int j=log[r-l+1];
        return min(dp[j][l],dp[j][r-(1<<j)+1]);
    }
}b;
struct SparseMax{
    int log[maxn];
    int dp[max_logn][maxn];
    SparseMax(){
        log[1] = 0;
        for (int i = 2; i < maxn; i++)
            log[i] = log[i/2] + 1;
    }
    void build(vector<int> b)
    {
        int n=b.size();
        for (int i = 0; i < n; ++i){
            dp[0][i]=b[i];
        }
        for (int j = 1; j < max_logn; j++)
            for (int i = 0; i + (1 << j) < maxn; i++)
                dp[j][i] = max(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
    }
    int query(int l,int r)
    {
        if(l>r)return M;
        int j=log[r-l+1];
        return max(dp[j][l],dp[j][r-(1<<j)+1]);
    }
}a;

void solve(){
	int n;
	cin>>n;
	vector<int> va(n),vb(n);
	rep(i,0,n){
		cin>>va[i];
	}
	rep(i,0,n){
		cin>>vb[i];
	}
	a.build(va);
	b.build(vb);
	
	int L,U,ans=0;
	
	rep(i,0,n){
		if(va[i] > vb[i] || a.query(i,n-1) < b.query(i,n-1))continue;
		int mx,mn;
		L=i,U=n-1;
		while(L<=U){
			int m=(L+U)/2;
			if(a.query(i,m) < b.query(i,m)){
				L=m+1;
			}
			else{
				U=m-1;
				mn = m;
			}
		}
		L=i,U=n-1;
		while(L<=U){
			int m=(L+U)/2;
			if(a.query(i,m) > b.query(i,m)){
				U=m-1;
			}
			else{
				L=m+1;
				mx=m;
			}
		}
		if(mx>=mn){
			ans += mx-mn+1;
		}
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}