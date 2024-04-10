#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define mo 1000000007
using namespace std;
int n,m;
int f[2][2][2][155][155];
inline int su(int f[155][155],int x1,int x2,int y1,int y2){
    int ans=f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1];
    return (ans%mo+mo)%mo;
}
int main()
{
    scanf("%d%d",&n,&m);
    int ans=0;
    for (int i=1;i<=n;i++){
        memset(f[i&1],0,sizeof(f[i&1]));
        for (int l=1;l<=m;l++)
            for (int r=l;r<=m;r++){
                f[i&1][0][0][l][r]=1+su(f[!(i&1)][0][0],l,r,l,r);
                f[i&1][1][0][l][r]=su(f[!(i&1)][1][0],1,l,l,r)+su(f[!(i&1)][0][0],1,l-1,l,r);
                f[i&1][0][1][l][r]=su(f[!(i&1)][0][1],l,r,r,m)+su(f[!(i&1)][0][0],l,r,r+1,m);
                if(f[i&1][1][0][l][r]>=mo)f[i&1][1][0][l][r]-=mo;
                if(f[i&1][0][1][l][r]>=mo)f[i&1][0][1][l][r]-=mo;
                f[i&1][1][1][l][r]=(0ll+su(f[!(i&1)][1][1],1,l,r,m)+su(f[!(i&1)][0][0],1,l-1,r+1,m)+su(f[!(i&1)][0][1],1,l-1,r,m)+su(f[!(i&1)][1][0],1,l,r+1,m))%mo;
                ans=(0ll+ans+f[i&1][0][0][l][r]+f[i&1][0][1][l][r]+f[i&1][1][0][l][r]+f[i&1][1][1][l][r])%mo;
            }
        for (int p=0;p<=1;p++)
            for (int q=0;q<=1;q++){
                for (int l=1;l<=m;l++)
                    for (int r=1;r<=m;r++){
                        f[i&1][p][q][l][r]+=f[i&1][p][q][l][r-1];
                        if(f[i&1][p][q][l][r]>=mo)f[i&1][p][q][l][r]-=mo;
                    }
                for (int l=1;l<=m;l++)
                    for (int r=1;r<=m;r++){
                        f[i&1][p][q][l][r]+=f[i&1][p][q][l-1][r];
                        if(f[i&1][p][q][l][r]>=mo)f[i&1][p][q][l][r]-=mo;
                    }
            }
    }
    printf("%d\n",ans);
    return 0;
}