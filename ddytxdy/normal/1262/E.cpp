#include<bits/stdc++.h>
using namespace std;
const int N=4e6+50;
int n,m;
struct node{char s[N];char *operator [](int x){return s+(x-1)*m;}}c;
struct node1{int a[N];int *operator [](int x){return a+x*(m+2);}}s,t;
int check(int x1,int y1,int x2,int y2){return x1>=1&&x2<=n&&y1>=1&&y2<=m&&!(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);}
bool check(int x){
    memset(t.a,0,sizeof(t.a));
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        int x1=i-x,y1=j-x,x2=i+x,y2=j+x;
        if(check(x1,y1,x2,y2))t[x1][y1]++,t[x2+1][y1]--,t[x1][y2+1]--,t[x2+1][y2+1]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            t[i][j]=t[i-1][j]+t[i][j-1]-t[i-1][j-1]+t[i][j];
            if(c[i][j]=='X'&&!t[i][j])return 0;
        }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(c[i][j]=='.');
    int l=0,r=min(n,m),ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++){
        int x1=i-ans,y1=j-ans,x2=i+ans,y2=j+ans;
        putchar(check(x1,y1,x2,y2)?'X':'.');
    }
    return 0;
}