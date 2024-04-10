#include<bits/stdc++.h>
int main(){
    int T;scanf("%d",&T);
    while(T--){
        long long a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
        long long m = std::min(b,c);
        if(a == b && a == c){
            puts("1");
            continue;
        }
        printf("%lld\n",a+1-std::min(b,c));
    }
    return 0;
}