#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
ll dp[maxn][2][2];
ll n,k;
int CUR;
int res[maxn];
ll dfs(int cur, bool f1, bool f2){
    if (dp[cur][f1][f2] != -1)return dp[cur][f1][f2];
    ll &ans = dp[cur][f1][f2] = 0;
    int lpos = cur;
    int rpos = n + 1 - cur;
    if (lpos > rpos)return ans = 1;
    for (int l = 0;l < 2;l ++){
        for (int r = 0;r < 2;r ++){
            if (lpos <= CUR && res[cur] != l)continue;
            if (rpos <= CUR && res[rpos] != r)continue;
            if(!f1 && l> r)continue;
            if (!f2 && l == 1 && r == 1)continue;
            if (lpos == rpos && l != r)continue;
            if (cur == 1 && l == 1)continue;
            bool ff1 = f1 || l < r;
            bool ff2 = f2 || (l == 0 && r == 0);
            ans += dfs(cur+1,ff1,ff2);
        }
    }
    return ans;
}
void clear(){
    for (int j=1;j<=n;j++){
        for (int f1 = 0;f1 < 2;f1 ++){
            for (int f2 = 0;f2 < 2;f2 ++){
                dp[j][f1][f2] = -1;
            }
        }
    }
}
void debug(){
    for (int j=1;j<=n;j++){
        for (int f1 = 0;f1 < 2;f1 ++){
            for (int f2 = 0;f2 < 2;f2 ++){
                if (dp[j][f1][f2] != -1){
                    cerr<<"dp["<<j<<"]["<<f1<<"]["<<f2<<"]="<<dp[j][f1][f2]<<endl;
                }
            }
        }
    }
}
int main(){
    cin>>n>>k;
    k++;
    clear();
    CUR = 0;
    ll t = dfs(1,0,0);
  //  debug();
  //  cerr<<t<<endl;
    if(t< k){
        puts("-1");
        return 0;
    }
    for (CUR=1;CUR<=n;CUR++){
        res[CUR] = 0;
        clear();
        ll t = dfs(1,0,0);
        if (t < k){
            k -= t;
            res[CUR] = 1;
        }
      //  cerr<<CUR<<" "<<k<<endl;
    }
    for (int i=1;i<=n;i++){
        printf("%d",res[i]);
    }
    puts("");
    return 0;
}