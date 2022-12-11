#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int t,x,y,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&x,&y,&a,&b);
        y-=x;a+=b;
        if(y%a==0)printf("%d\n",y/a);
        else puts("-1");
    }
    return 0;
}