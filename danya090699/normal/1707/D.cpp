#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10;
int dp[sz][sz], prefdp[sz][sz], n, mod, tr[sz][sz];
vector <int> sv[sz];
void dfs(int v, int pr)
{
    vector <int> to;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne != pr)
        {
            dfs(ne, v), to.push_back(ne);
        }
    }
    int dp2[to.size()];
    for(int a=0; a<to.size(); a++) dp2[a]=0;
    for (int k = 1; k < n; k++)
    {
        dp[v][k]=1;
        for(int a=0; a<to.size(); a++) dp[v][k] = (1ll * dp[v][k] * prefdp[to[a]][k])%mod;
        if (v and k>1) {
            int pref[to.size() + 1], suf[to.size() + 1];
            pref[0] = 1;
            for (int a = 0; a < to.size(); a++) pref[a + 1] = (1ll * pref[a] * prefdp[to[a]][k - 1]) % mod;
            suf[to.size()] = 1;
            for (int a = int(to.size()) - 1; a >= 0; a--) suf[a] = (1ll * suf[a + 1] * prefdp[to[a]][k - 1]) % mod;

            for (int a = 0; a < to.size(); a++) {
                int ne = to[a];
                dp2[a] = (dp2[a] + 1ll * pref[a] * suf[a + 1]) % mod;
                dp[v][k] = (dp[v][k] + 1ll * dp[ne][k] * dp2[a]) % mod;
            }
        }
        prefdp[v][k] = (prefdp[v][k-1] + dp[v][k])%mod;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin>>n>>mod;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    tr[0][0]=1;
    for(int a=0; a<=n; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=(tr[a-1][b-1]+tr[a-1][b])%mod;
    }
    dfs(0, -1);
    int an[n];
    for(int k=1; k<n; k++)
    {
        an[k]=dp[0][k];
        for(int a=1; a<k; a++)
        {
            an[k]-=(1ll*an[a]*tr[k][a])%mod;
            if(an[k]<0) an[k]+=mod;
        }
        cout<<an[k]<<" ";
    }
}