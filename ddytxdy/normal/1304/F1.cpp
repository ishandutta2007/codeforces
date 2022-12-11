#include<bits/stdc++.h>
using namespace std;
const int N=2e4+50;
int n,m,k,s[60][N],f[N],g[N],q[N],l,r,ans;
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
int calc1(int id,int x){return f[x]-s[id][x+k-1];}
int calc2(int id,int x){return f[x]+s[id][x-1];}
int main(){
    n=read();m=read();k=read();
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s[i][j]=s[i][j-1]+read();
    for(int i=1;i<=m-k+1;i++)f[i]=s[1][i+k-1]-s[1][i-1]+s[2][i+k-1]-s[2][i-1];
    for(int i=2;i<=n;i++){
        l=1;r=0;
        memset(g,0,sizeof(g));
        for(int j=1,mx=0;j<=m-k+1;j++){
            while(l<=r&&calc1(i,j)>=calc1(i,q[r]))r--;
            q[++r]=j;
            if(l<=r&&q[l]+k-1<j)l++;
            if(j-k>=1)mx=max(mx,f[j-k]);
            g[j]=max(g[j],max(s[i][j+k-1]+calc1(i,q[l]),s[i][j+k-1]-s[i][j-1]+mx));
        }
        l=1;r=0;
        for(int j=m-k+1,mx=0;j;j--){
            while(l<=r&&calc2(i,j)>=calc2(i,q[r]))r--;
            q[++r]=j;
            if(l<=r&&q[l]>j+k-1)l++;
            if(j+k<=m)mx=max(mx,f[j+k]);
            g[j]=max(g[j],max(calc2(i,q[l])-s[i][j-1],s[i][j+k-1]-s[i][j-1]+mx));
        }
        for(int j=1;j<=m-k+1;j++)f[j]=g[j]+s[i+1][j+k-1]-s[i+1][j-1];
    }
    for(int i=1;i<=m-k+1;i++)ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}
// 3 4 2
// 1 2 3 4
// 2 3 4 5
// 3 4 5 6