#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int T,n,k;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        if(n<1ll*k*k)puts("NO");
        else if((k&1)^(n&1))puts("NO");
        else puts("YES");
    }
    return 0;
}