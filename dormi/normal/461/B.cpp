#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int MAXN=2e5+1;
lli mod=1e9+7;
lli fastpow(lli a,lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
inline lli fix(lli a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
lli dp[MAXN][2];
vector<int> matrix[MAXN];
bool col[MAXN];
void dfs(int loc, int par){
    lli mult0=1;
    for(int x:matrix[loc]){
        if(x!=par){
            dfs(x,loc);
            mult0=mult0*dp[x][0]%mod;
        }
    }
    if(!col[loc]){
        lli totsum=0;
        for(int x:matrix[loc]){
            if(x!=par){
                totsum=fix(totsum+((mult0*fastpow(dp[x][0],mod-2)%mod)*dp[x][1]%mod));
            }
        }
        dp[loc][0]=fix(totsum+mult0),dp[loc][1]=totsum;
    }
    else dp[loc][0]=mult0,dp[loc][1]=mult0;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    for(int i=1;i<n;i++){
        cin>>a;
        matrix[a].push_back(i);
        matrix[i].push_back(a);
    }
    for(int i=0;i<n;i++)cin>>col[i];
    dfs(0,-1);
    printf("%lli\n",dp[0][1]);
    return 0;
}