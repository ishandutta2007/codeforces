#include <bits/stdc++.h>
using namespace std;
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

const int N=2e5+5;

int last[N];
int pre[N];
int post[N];
int p[N];
int a[N];

int pdp[N];
int ndp[N];
vector<int> dp;

vector<int> pos[N];


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
}spmin;

void solve(){
	dp.resize(N);
	int n,m,q;
	cin>>n>>m>>q;
	rep(i,1,n+1){
		cin>>p[i];
	}
	rep(i,1,m+1){
		cin>>a[i];
		pos[a[i]].pb(i);
	}
	
	rep(i,2,n+1){
		pre[p[i]]=p[i-1];
	}
	
	pdp[0]=0;
	rep(i,1,m+1){
		if(a[i]==p[1]){
			pdp[i]=i;
		}
		else{
			pdp[i]=pdp[last[pre[a[i]]]];
		}
		last[a[i]]=i;
	}
	
	rep(i,1,n+1)last[i]=m+1;
	rep(i,1,n){
		post[p[i]]=p[i+1];
	}
	
	ndp[m+1]=m+1;
	for(int i=m;i>0;i--){
		if(a[i]==p[n]){
			ndp[i]=i;
		}
		else{
			ndp[i]=ndp[last[post[a[i]]]];
		}
		last[a[i]]=i;
	}
	
	rep(i,1,m+1){
		if(a[i] == p[1]){
			dp[i]=ndp[i];
			continue;
		}
		int x=ndp[i];
		int L=0,U=sz(pos[pre[a[i]]])-1;
		int ans=U+1;
		while(L<=U){
			int m=(L+U)/2;
			if(pdp[pos[pre[a[i]]][m]] > x){
				ans=m;
				U=m-1;
			}
			else{
				L=m+1;
			}
		}
		if(ans == sz(pos[pre[a[i]]])){
			dp[i]=m+1;
		}
		else{
			dp[i]=pos[pre[a[i]]][ans];
		}
	}
	
	spmin.build(dp);
	rep(i,0,q){
		int l,r;
		cin>>l>>r;
		int k=spmin.query(l,r);
		cout<<(k<=r);
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