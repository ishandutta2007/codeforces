#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int n,m,w,ans,pw[300005];
ll f[300005][2];
vector<string> g;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pw[0]=1;
    pw[1]=2;
    for(int i=2;i<=300000;i++){
        f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
        f[i][1]=(f[i-1][0]+f[i-2][0]+f[i-2][1]+pw[i-2])%mod;
        pw[i]=pw[i-1]*2%mod;
    }

    cin>>n>>m;
    g.resize(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
        for(int j=0;j<m;j++)w+=g[i][j]=='o';
    }
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<=m;j++){
            if(j!=m&&g[i][j]=='o')c++;
            else{
                ans=(ans+(f[c][0]+f[c][1])*pw[w-c])%mod;
                c=0;
            }
        }
    }
    for(int j=0;j<m;j++){
        int c=0;
        for(int i=0;i<=n;i++){
            if(i!=n&&g[i][j]=='o')c++;
            else{
                ans=(ans+(f[c][0]+f[c][1])*pw[w-c])%mod;
                c=0;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}