#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int n,m;
char g[255][255];
int f[255][1<<15],h[255][1<<15];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>(m<=n?g[i][j]:g[j][i]);
        }
    }
    if(m>n)swap(n,m);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int s=0;s<1<<m;s++){
            int pass=s,empty=0;
            for(int j=1;j<=m;j++)if(g[i][j]=='x')pass&=~(1<<j-1);
            else empty|=1<<j-1;
            int t=empty+1;
            do{
                t=t-1&empty;
                int nt=t;
                for(int j=2;j<=m;j++)if(g[i][j]=='.'&&g[i][j-1]=='.')nt|=(nt>>j-2&1)<<j-1;
                if((nt|pass)==empty){
                    f[i][t|pass]=(f[i][t|pass]+f[i-1][s])%mod;
                    h[i][t|pass]=(h[i][t|pass]+h[i-1][s])%mod;
                }
                if(__builtin_popcount(empty&~(nt|pass))==1){
                    h[i][t|pass]=(h[i][t|pass]+f[i-1][s])%mod;
                }
            }while(t);
        }
    }
    cout<<(accumulate(f[n],f[n]+(1<<m),0ll)+accumulate(h[n],h[n]+(1<<m),0ll))%mod;

    return 0;
}