#include <stdio.h>
#include <string.h>
#include <math.h>
#define lli long long int
#define sf scanf
#define pf printf
int main(){
    lli n,t,c,r=0,s,m;
    scanf("%I64d %I64d",&n,&t);
    lli a[n];
    scanf("%I64d",&a[0]);
    m=a[0];
    for(lli i=1;i<n;i++){
        scanf("%I64d",&a[i]);
        if(a[i]<m)m=a[i];
    }
    do{
        c=0;s=0;
        for(lli i=0;i<n;i++){
            if(a[i]<=t){s+=a[i];t-=a[i];c++;}
        }
if(s>0){
        r+=(1+t/s)*c;
        t=t%s;}
        if(t<m)break;
    }while(c>0);
    pf("%I64d",r);
}