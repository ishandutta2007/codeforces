#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 1024
struct data{
    int x,y;
    bool operator<(data b)const{return x<b.x||(x==b.x&&y<b.y);}
}a[SIZE];
main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        a[i]=(data){x,i+1};
    }
    sort(a,a+n);
    if(a[0].x==a[n-1].x){
        puts("Exemplary pages.");
    }
    else if(n==2){
        if((a[0].x+a[1].x)%2!=0)puts("Unrecoverable configuration.");
        else printf("%d ml. from cup #%d to cup #%d.\n",(a[1].x-a[0].x)>>1,a[0].y,a[1].y);
    }
    else{
        if(a[1].x!=a[n-2].x)puts("Unrecoverable configuration.");
        else if((a[0].x+a[n-1].x)%2!=0||a[0].x+a[n-1].x!=a[1].x*2)puts("Unrecoverable configuration.");
        else printf("%d ml. from cup #%d to cup #%d.\n",(a[n-1].x-a[0].x)>>1,a[0].y,a[n-1].y);
    }
}