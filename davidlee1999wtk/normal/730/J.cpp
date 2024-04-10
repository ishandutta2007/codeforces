#include <bits/stdc++.h>

#define rep(i,l,r) for (int i=l;i<=r;++i)
#define REP(i,r,l) for (int i=r;i>=l;--i)
using namespace std;

const int N=1E2+10;
int a[N],b[N];
int f[N*N][N];
int n,m,ans;

int main(){
    scanf("%d",&n);
    int tota=0,totb=0;
    rep(i,1,n) scanf("%d",a+i),tota+=a[i];
    rep(i,1,n) scanf("%d",b+i),totb+=b[i];
    rep(i,0,totb) rep(k,0,n) f[i][k]=-1;
    f[0][0]=0;
    rep(i,1,n)
        REP(j,totb,0)
            rep(k,1,i)
            if (j-b[i]>=0 && f[j-b[i]][k-1]!=-1){
                f[j][k]=max(f[j][k],f[j-b[i]][k-1]+a[i]);
            }

    int x=0;
    rep(i,1,n)
        if (!x){ 
            rep(j,tota,totb) 
               if (f[j][i]!=-1) {x=i; break;}
        }
    rep(i,tota,totb) ans=max(ans,f[i][x]);
    printf("%d %d\n",x,tota-ans); 
}