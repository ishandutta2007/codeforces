#include<bits/stdc++.h>
using namespace std;
const int N=110,mod=998244353;
int n,l[N],r[N],c[N],m,s[N],f[N][N],inv[N],ans,tmp=1;
int power(int x,int y){
    int z=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
    return z;
}
int main(){
    scanf("%d",&n);inv[1]=1;
    for(int i=2;i<=n;i++)inv[i]=mod-1ll*mod/i*inv[mod%i]%mod;
    for(int i=1,x,y;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]),c[i]=l[i],c[i+n]=++r[i],tmp=1ll*tmp*(r[i]-l[i])%mod;
    sort(c+1,c+n*2+1);m=unique(c+1,c+n*2+1)-c-1;
    reverse(l+1,l+n+1);reverse(r+1,r+n+1);
    for(int i=1;i<=n;i++)
        l[i]=lower_bound(c+1,c+m+1,l[i])-c,
        r[i]=lower_bound(c+1,c+m+1,r[i])-c;
    for(int i=0;i<=m;i++)s[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            bool fl=j>=l[i]&&j<r[i];
            for(int k=i;k>1;k--)
                f[j][k]=fl?1ll*f[j][k-1]*(c[j+1]-c[j]+k-1)%mod*inv[k]%mod:0;
            f[j][1]=fl?1ll*s[j-1]*(c[j+1]-c[j])%mod:0;
        }
        s[0]=0;
        for(int j=1;j<m;j++){
            s[j]=s[j-1];
            for(int k=1;k<=i;k++)(s[j]+=f[j][k])%=mod;
        }
    }
    for(int i=1;i<m;i++)for(int j=1;j<=n;j++)(ans+=f[i][j])%=mod;
    cout<<(1ll*ans*power(tmp,mod-2)%mod+mod)%mod;
    return 0;
}