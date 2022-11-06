#include<bits/stdc++.h>
using namespace std;
char s[20];
void work(){
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    long long x=c*b+a,y=b,z=c;
    printf("%lld %lld %lld\n",x,y,z);
    assert(x%y==a);
    assert(y%z==b&&z%x==c);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}