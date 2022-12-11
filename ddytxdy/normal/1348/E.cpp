#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=520;
const LL inf=0xcfcfcfcfcfcfcfcf;
int n,k,a[N],b[N];LL f[N][N],ans;
void cmax(LL &x,LL y){y>x?x=y:0;}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
    memset(f,0xcf,sizeof(f));f[0][0]=0;
    for(int i=1,sum=0;i<=n;i++){
        for(int j=0;j<k;j++)if(f[i-1][j]!=inf){
            int l=sum-j;if(l<0)l+=k;
            for(int x=max(1,k-b[i]);x<=min(k-1,a[i]);x++){
                int xx=j+a[i]-x,yy=l+b[i]-k+x;
                cmax(f[i][xx%k],f[i-1][j]+xx/k+yy/k+1);
            }
            cmax(f[i][(j+a[i])%k],f[i-1][j]+(j+a[i])/k+(l+b[i])/k);
        }
        (sum+=a[i]+b[i])%=k;
    }
    for(int i=0;i<k;i++)cmax(ans,f[n][i]);
    cout<<ans;
    return 0;
}