#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 300001
int a[SIZE];
long long an[SIZE],dp[SIZE];
struct data{
    int x,y,No;
    void scan(){scanf("%d%d",&x,&y);}
    bool operator<(data b)const{
        if(y<b.y)return 0;
        if(y>b.y)return 1;
        int r1=x%y,r2=b.x%y;
        if(r1<r2)return 0;
        if(r1>r2)return 1;
        return No<b.No;
    }
}d[SIZE];
main(){
    int n,i,j,k,mi,p;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&p);
    for(i=0;i<p;i++)d[i].scan(),d[i].No=i;
    sort(d,d+p);
    for(i=0;i<p;i+=j){
        int tmp=d[i].x%d[i].y;
        mi=n;
        for(j=0;i+j<p;j++){
            if(d[i].y!=d[i+j].y||d[i+j].x%d[i].y!=tmp)break;
            mi=min(mi,d[i+j].x);
        }
        k=d[i].x+(n-d[i].x)/d[i].y*d[i].y;
        dp[k]=a[k];
        for(k-=d[i].y;k>=mi;k-=d[i].y)
            dp[k]=a[k]+dp[k+d[i].y];
        for(k=0;k<j;k++)an[d[i+k].No]=dp[d[i+k].x];
    }
    for(i=0;i<p;i++)printf("%I64d\n",an[i]);
}