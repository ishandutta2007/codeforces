#include<stdio.h>
#include<algorithm>
using namespace std;
int d[1024];
main(){
    int n,m,k,t,x,y,i;
    scanf("%d%d%d%d",&n,&m,&k,&t);
    for(i=0;i<k;i++){
        scanf("%d%d",&x,&y);
        d[i]=(x-1)*m+y-1;
    }
    sort(d,d+k);
    while(t--){
        scanf("%d%d",&x,&y);
        x=(x-1)*m+(y-1);
        for(i=0;i<k&&d[i]<x;i++);
        if(d[i]==x)puts("Waste");
        else{
            x-=i;
            if(x%3==0)puts("Carrots");
            else if(x%3==1)puts("Kiwis");
            else puts("Grapes");
        }
    }
}