#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,x,y,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        x=(a-1)/c+1;y=(b-1)/d+1;
        if(x+y>k)puts("-1");
        else printf("%d %d\n",x,y);
    }
    return 0;
}