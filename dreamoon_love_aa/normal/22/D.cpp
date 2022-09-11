#include<stdio.h>
#include<algorithm>
using namespace std;
int used[1024],res[1024];
struct data{
    int x,y;
    bool operator<(data b)const{return y<b.y;}
}a[1024];
main(){
    int n,i,an=0,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(used[i])continue;
        res[an++]=a[i].y;
        for(j=i+1;j<n;j++)
            if(a[j].x<=a[i].y)used[j]=1;
    }
    printf("%d\n",an);
    for(i=0;i<an;i++){
        if(i)putchar(' ');
        printf("%d",res[i]);
    }
    puts("");
}