/*dp[i][j] = rightmost position in t s[1..i] can match using j segment.

dp[i+1][j] = max(dp[i][j],dp[i+1][j])
dp[i+lcp(s[i],t[dp[i][j]])][j+1] = dp[i][j] + lcp(s[i],t[dp[i][j]])
  */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 1e5+100;
ULL Seed_Pool[]={911,146527,19260817,91815541};
ULL Mod_Pool[]={29123,998244353,1000000009,4294967291ull};
struct Hash_1D{
    ULL Seed,Mod;
    ULL bas[maxn];ULL sum[maxn];
    void init(int seedIndex,int modIndex,const char *s,int n){
        Seed = Seed_Pool[seedIndex];
        Mod = Mod_Pool[modIndex];
        bas[0]=1;
        for (int i=1;i<=n;i++){
            bas[i] = bas[i-1]*Seed%Mod;
        }
        for (int i=1;i<=n;i++){
            sum[i] = (sum[i-1]*Seed%Mod+s[i])%Mod;
        }
    }
    ULL getHash(int l,int r){
        return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
    }
}hs,ht;
char s[maxn],t[maxn];
int n,m;
int X;
int dp[maxn][31];
bool in[maxn][31];
int get_lcp(int poss,int post){
    int r = min(n - poss , m - post) + 1;
    int l = 0;
    while (r - l > 1){
        int mid = l + r >> 1;
        ULL hval1 = hs.getHash(poss,poss + mid -1);
        ULL hval2 = ht.getHash(post,post + mid -1);
        if (hval1 == hval2)l = mid;
        else r = mid;
    }
    ULL hval1 = hs.getHash(poss, poss + r -1);
    ULL hval2 = ht.getHash(post, post + r -1);
    if (hval1 == hval2)return r;
    else return l;
}
int main(){
    scanf("%d",&n);scanf("%s",s+1);
    scanf("%d",&m);scanf("%s",t+1);
    hs.init(2,1,s,n);ht.init(2,1,t,m);
    scanf("%d",&X);
    memset(dp,-1,sizeof dp);
    dp[0][0] = 0;
    queue<tuple<int,int> > dp_list;
    dp_list.push({0,0});in[0][0] = 1;
    while (!dp_list.empty()){
        auto tp = dp_list.front();dp_list.pop();
        int i,j,k;
        tie(i,k) = tp;
        j = dp[i][k];
        in[i][k] = 0;
        /* s[i] t[j] using k segment */
//        cerr<<"("<<i<<","<<j<<") = "<<k<<endl;
        if (j == m){
            puts("YES");
            return 0;
        }
        /* s[i+1]not used */
        if (i == n)continue;
//        cerr<<dp[i+1][j] <<"   "<<dp[i][j]<<endl;
        if (dp[i+1][k] < dp[i][k]){
            dp[i+1][k] = dp[i][k];
            if (!in[i+1][k]){
                in[i+1][k] = 1;
                dp_list.push({i+1,k});
            }
        }
        /* s[i+1] used */
        if (k == X || i == n)continue;
        int lcp = get_lcp(i+1,j+1);
        if (dp[i+lcp][k+1] < dp[i][k] + lcp){
            dp[i+lcp][k+1] = dp[i][k] + lcp;
            if (!in[i+lcp][k+1]){
                in[i+lcp][k+1] = 1;
                dp_list.push({i+lcp,k+1});
            }
        }
    }
    puts("NO");
    return 0;
}