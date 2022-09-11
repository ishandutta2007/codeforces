#include<stdio.h>
#include<algorithm>
using namespace std;
struct data{
    int x,y;
    bool operator<(data b)const{return y>b.y;}
    void scan(){scanf("%d%d",&x,&y);}
}a[22];
main(){
    int n,m,i,an=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)a[i].scan();
    sort(a,a+m);
    i=0;
    while(n>0&&i<m){
        if(n>a[i].x){
            n-=a[i].x;
            an+=a[i].x*a[i].y;
        }
        else{
            an+=a[i].y*n;
            n=0;
        }
        i++;
    }
    printf("%d\n",an);
}