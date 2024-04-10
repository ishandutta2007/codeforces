#include<stdio.h>
#include<algorithm>
using namespace std;
struct data{
    int x,y;
    bool operator<(data b)const{return y<b.y;}
}a[1010];
int d[1010];
main(){
    int i,n,x,y,z,m,an=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        a[i]=(data){i+1,x};
    }
    for(i=1;i<=n;i++)d[i]=-1;
    sort(a,a+n);
    scanf("%d",&m);
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        if(d[y]==-1||d[y]>z)d[y]=z;
    }
    for(i=1;i<=n;i++){
        if(i==a[n-1].x)continue;
        if(d[i]<0)break;
        an+=d[i];
    }
    if(i<=n)puts("-1");
    else printf("%d\n",an);
}