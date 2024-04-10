#include <bits/stdc++.h>
using namespace std;
long long a,s=0,m=0,n;
int main() {
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&a);
        long long x=min(m,a/2);
        m+=a-x*3-(a-x*2)/3*3;
        s+=x+(a-x*2)/3;
    }
    printf("%lld\n",s);
    return 0;
}