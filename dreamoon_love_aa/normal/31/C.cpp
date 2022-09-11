#include<stdio.h>
#include<algorithm>
using namespace std;
int an[2],ann;
struct data{
    int l,r,x;
    bool operator<(data b)const{return l<b.l||(l==b.l&&r<b.r);}
}a[5001];
main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].x=i;
    }
    sort(a+1,a+1+n);
    for(i=2;i<=n;i++)
        if(a[i].l<a[i-1].r)break;
    if(i>n){
        printf("%d\n",n);
        for(i=1;i<=n;i++){
            if(i!=1)putchar(' ');
            printf("%d",i);
        }
        puts("");
    }
    else{
        if(i+1>n||a[i+1].l>=a[i-1].r){
            for(j=i+2;j<=n;j++)
                if(a[j].l<a[j-1].r)break;
            if(j>n)an[ann++]=a[i].x;
        }
        for(j=i+1;j<=n;j++)
            if(a[j].l<a[j-1].r)break;
        if(j>n)an[ann++]=a[i-1].x;
        printf("%d\n",ann);
        if(ann){
            sort(an,an+ann);
            for(i=0;i<ann;i++){
                if(i)putchar(' ');
                printf("%d",an[i]);
            }
            puts("");
        }
    }
}