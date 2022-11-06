#include<bits/stdc++.h>
using namespace std;
int a[55];
void work(){
    int n,k;
    scanf("%d%d",&n,&k);
    int s=0,i,j,x;
    for(i=1;i<=n;++i){
        scanf("%d",&x);
        s|=x;
    }
    if(s)puts("YES");
    else puts("NO");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}