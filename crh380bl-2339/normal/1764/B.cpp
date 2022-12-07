#include<bits/stdc++.h>
using namespace std;
set<int>S;
void work(){
    int n,g=0,i,x,mx=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&x);
        g=__gcd(g,x);
        mx=max(mx, x);
    }
    printf("%d\n",mx/g);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}