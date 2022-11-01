#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

char s[1005],t[1005];
int n,m,f[1005][1005],g[1005][1005],ps[1005],pt[1005],ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1>>t+1;
    n=strlen(s+1);
    m=strlen(t+1);
    for(int i=1;i<=n;i++){
        f[i][0]=s[i]!=s[i-1]?f[i-1][0]+1:1;
        ps[i]=s[i]!=s[i-1]?ps[i-1]+1:1;
    }
    for(int i=1;i<=m;i++){
        g[0][i]=t[i]!=t[i-1]?g[0][i-1]+1:1;
        pt[i]=t[i]!=t[i-1]?pt[i-1]+1:1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int &ff=f[i][j],&gg=g[i][j];
            ff=1;
            if(s[i]!=s[i-1])ff=(ff+f[i-1][j])%mod;
            if(s[i]!=t[j])ff=(ff+g[i-1][j])%mod;
            gg=1;
            if(t[j]!=t[j-1])gg=(gg+g[i][j-1])%mod;
            if(t[j]!=s[i])gg=(gg+f[i][j-1])%mod;
            ans=(ans+f[i][j]-ps[i])%mod;
            ans=(ans+g[i][j]-pt[j])%mod;
        }
    }
    cout<<(ans+mod)%mod;

    return 0;
}