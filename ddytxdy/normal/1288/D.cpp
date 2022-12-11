#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50,mod=1e9+7,M=500;
int t,n,m,J[N],I[N],a[N][10],mx=0,ans=-1,A,B,Ans[M],id[M];
int C(int n,int m){return 1ll*J[n]*I[m]%mod*I[n-m]%mod;}
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
int main(){
    // freopen("test.in","r",stdin);
    n=read();m=read();mx=1<<m;
    for(int i=1;i<=n;i++)for(int j=0;j<m;j++)a[i][j]=read();
    for(int i=1;i<mx;i++){
        Ans[i]=-1;
        for(int j=1;j<=n;j++){
            int dat=1e9;
            for(int k=0;k<m;k++)if(i>>k&1)dat=min(dat,a[j][k]);
            if(dat>Ans[i])Ans[i]=dat,id[i]=j;
        }
    }
    for(int i=1;i<mx-1;i++){
        int dat=min(Ans[i],Ans[mx-1-i]);
        if(dat>ans)ans=dat,A=id[i],B=id[mx-1-i];
    }
    if(Ans[mx-1]>ans)A=B=id[mx-1];
    printf("%d %d\n",A,B);
}