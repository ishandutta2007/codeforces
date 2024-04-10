#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n,m,U,D,L,R,num;char c[N][N];
int u,d,l,r;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);L=l=1e9;U=u=1e9;R=r=0;D=d=0;num=0;
        for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(c[i][j]=='A'){
            L=min(L,j);U=min(U,i);R=max(R,j);D=max(D,i);num++;
        }
        else l=min(l,j),u=min(u,i),r=max(r,j),d=max(d,i);
        if(!R)puts("MORTAL");
        else if(n*m==num)puts("0");
        else if(l>1||r<m||u>1||d<n)puts("1");
        else{
            bool done=0;
            for(int i=1;i<=n;i++){
                bool flag=1;
                for(int j=1;j<=m;j++)if(c[i][j]!='A')flag=0;
                done|=flag;
            }
            for(int i=1;i<=m;i++){
                bool flag=1;
                for(int j=1;j<=n;j++)if(c[j][i]!='A')flag=0;
                done|=flag;
            }
            if(done||c[1][1]=='A'||c[1][m]=='A'||c[n][1]=='A'||c[n][m]=='A')puts("2");
            else if(L==1||R==m||U==1||D==n)puts("3");
            else puts("4");
        }
        
    }   
    return 0;
}