#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 5000000
struct data{
    int x,v;
    void scan(){scanf("%d%d",&x,&v);}
}a[SIZE];
double f(data a1[],int n1,data a2[],int n2){
    if(n2==0)return 1e12;
    int i;
    double left=0,right=(double)(a2[0].x-a1[n1-1].x)/(a1[n1-1].v-a2[0].v),mid,ma,mi;
    while(left+1e-12<right&&left+left*1e-12<right){
        mid=(left+right)/2;
        ma=-1e12;
        for(i=0;i<n1;i++)ma=max(ma,a1[i].x+a1[i].v*mid);
        mi=1e12;
        for(i=0;i<n2;i++)mi=min(mi,a2[i].x+a2[i].v*mid);
        if(mi<=ma)right=mid;
        else left=mid;
    }
    return left;
}
main(){
    int n,i,j;
    double an=1e12;
    scanf("%d",&n);
    for(i=0;i<n;i++)a[i].scan();
    for(i=0;i<n&&a[i].v<0;i++);
    for(;i<n;i+=j){
        for(j=0;i+j<n&&a[i+j].v>0;j++);
        int half=j;
        for(;i+j<n&&a[i+j].v<0;j++);
        an=min(an,f(a+i,half,a+i+half,j-half));
    }
    if(an==1e12)puts("-1");
    else printf("%.12lf\n",an);
}