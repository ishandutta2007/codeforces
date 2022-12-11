#include<bits/stdc++.h>
using namespace std;
const int N=520;
int n,m,q,s[4][N][N],id[N],s2[N/2][N][N],Mx;char c[N][N];
bool CK(int s[N][N],int x1,int y1,int x2,int y2,int op){
    int dat=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
    return op?dat:dat==(x2-x1+1)*(y2-y1+1);
}
bool ck(int x,int y,int len){
    int x0=x-len+1,y0=y-len+1,x1=x+len,y1=y+len;
    return CK(s[0],x0,y0,x,y,0)&&CK(s[1],x0,y+1,x,y1,0)&&CK(s[2],x+1,y0,x1,y,0)&&CK(s[3],x+1,y+1,x1,y1,0);
}
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
int main(){
    id['R']=0;id['G']=1;id['Y']=2;id['B']=3;
    scanf("%d%d%d",&n,&m,&q);Mx=min(n/2,m/2);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<4;k++)
        s[k][i][j]=s[k][i-1][j]+s[k][i][j-1]-s[k][i-1][j-1]+(id[c[i][j]]==k);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        int mx=min(min(i,n-i),min(j,m-j));
        for(int k=1;k<=Mx;k++)s2[k][i][j]=s2[k][i-1][j]+s2[k][i][j-1]-s2[k][i-1][j-1];
        for(int k=1;k<=mx;k++)
            if(ck(i,j,k))s2[k][i][j]++;
            else break;
    }
    for(int i=1,x1,y1,x2,y2;i<=q;i++){
        x1=read(),y1=read();x2=read();y2=read();
        int l=1,r=min((x2-x1+1)/2,(y2-y1+1)/2),ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(CK(s2[mid],x1+mid-1,y1+mid-1,x2-mid,y2-mid,1))ans=mid,l=mid+1;
            else r=mid-1;
        }
        printf("%d\n",4*ans*ans);
    }
    return 0;
}