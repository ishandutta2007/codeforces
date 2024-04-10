#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=300005;
//i_am_noob
int n,a[maxn],x,cnt[maxn]={0},cnt1[maxn]={0},cnt2[pow2(7)],val[pow2(7)],dp[pow2(7)][pow2(7)],ans=inf;
vector<int> prime,vec[maxn];
bool isprime[maxn];

void find_prime(){
	isprime[0]=isprime[1]=false;
	rep2(i,2,maxn) isprime[i]=true;
	rep2(i,2,maxn){
		if(isprime[i]){
			prime.pb(i);
			for(int j=i*i; j<maxn; j+=i) isprime[j]=false;
		}
	}
}

int solve(int k){
    int m=sz(vec[k]);
    rep(pow2(m)) {cnt2[i]=0;val[i]=1;}
    rep(pow2(m)) rep1(j,m) if(i&pow2(j)) val[i]*=vec[k][j];
    rep3(i,pow2(m)-1,0){
        cnt2[i]=0;
        if(i==pow2(m)-1) cnt2[i]--;
        for(int subset=i; subset<pow2(m);subset=(subset+1)|i){
            if((__builtin_popcountll(subset)-__builtin_popcount(i))%2) cnt2[i]-=cnt1[val[subset]];
            else cnt2[i]+=cnt1[val[subset]];
        }
    }
    rep(pow2(m)) dp[0][i]=inf;
    dp[0][0]=0;
    rep2(i,1,pow2(m)+1) rep1(j,pow2(m)){
        if(cnt2[i-1]==0){
            dp[i][j]=dp[i-1][j];
            continue;
        }
        dp[i][j]=min(dp[i-1][j],dp[i-1][(i-1)&j]+1);
    }
    return dp[pow2(m)][pow2(m)-1]+1;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    find_prime();
    cin >> n;
    rep(n){
        cin >> a[i];
        for(auto p: prime){
            if(p*p>a[i]) break;
            while(a[i]%(p*p)==0) a[i]/=p;
        }
    }
    sort(a,a+n);
    n=unique(a,a+n)-a;
    if(a[0]==1){
        print1(1);
        return 0;
    }
    x=a[0];
    rep(n) x=__gcd(x,a[i]);
    if(x>1){
        print1(-1);
        return 0;
    }
    rep(n) cnt[a[i]]++;
    rep2(i,1,maxn) for(int j=i; j<maxn; j+=i) cnt1[i]+=cnt[j];
    rep(n){
        x=a[i];
        for(auto p: prime){
            if(p*p>x) break;
            if(x%p==0){
                vec[i].pb(p);
                x/=p;
            }
        }
        if(x>1) vec[i].pb(x);
    }
    rep(n) ans=min(ans,solve(i));
    print1(ans);
    return 0;
}