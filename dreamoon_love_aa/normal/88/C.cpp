#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct data{
    long long x,y;
    bool operator<(data b)const{
        return x<b.x||(x==b.x&&y>b.y);
    }
}d[2000000];
long long gcd(long long x,long long y){
    while((x%=y)&&(y%=x));
    return x+y;
}
long long lcm(long long x,long long y){
    return x*y/gcd(x,y);
}
main(){
    long long a,b,r,i,n=0,x,y;
    x=y=0;
    cin>>a>>b;
    r=lcm(a,b);
    for(i=a;i<=r;i+=a)d[n++]=(data){i,a};
    for(i=b;i<=r;i+=b)d[n++]=(data){i,b};
    d[n++]=(data){0,0};
    sort(d,d+n);
    for(i=1;i<n;i++){
        if(d[i].y==a)x+=d[i].x-d[i-1].x;
        else y+=d[i].x-d[i-1].x;
    }
    if(x>y)puts("Dasha");
    else if(x<y)puts("Masha");
    else puts("Equal");
}