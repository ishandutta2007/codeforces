#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;
const int off=1001;

int n,f[2005][2005],g[2005][2005];
char s[2005],t[2005];

void mian(){
    cin>>n>>s>>t;
    for(int i=0;i<n;i+=2){
        if(s[i]!='?')s[i]^=1;
        if(t[i]!='?')t[i]^=1;
    }
    for(int i=1;i<=n;i++){
        memset(f[i],0,sizeof(f[i]));
        memset(g[i],0,sizeof(g[i]));
    }
    f[0][off]=1;
    for(int i=0;i<n;i++){
        for(int j=-1000;j<=1000;j++)if(f[i][j+off]){
            int cf=f[i][j+off],cg=g[i][j+off];
            for(int vs=s[i]=='?'?0:s[i]-'0';vs<=(s[i]=='?'?1:s[i]-'0');vs++){
                for(int vt=t[i]=='?'?0:t[i]-'0';vt<=(t[i]=='?'?1:t[i]-'0');vt++){
                    f[i+1][j+vs-vt+off]=(f[i+1][j+vs-vt+off]+cf)%mod;
                    g[i+1][j+vs-vt+off]=(g[i+1][j+vs-vt+off]+cg+(ll)cf*abs(j+vs-vt))%mod;
                }
            }
        }
    }
    cout<<g[n][off]<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}