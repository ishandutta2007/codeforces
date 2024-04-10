#include <stdio.h>
#include <string.h>
#include <math.h>
#define ll long long
#define pf printf
#define sf scanf
#define ron(i,n) for(int i=0;i<n;i++)
#define pfd(a) printf("%d",a)
#define sfd(a) scanf("%d",&a)

int main(){
    ll int b,ans=1,z;
    sf("%I64d",&b);
    z=sqrt(b);
    for(ll int i=2;i<=b;i++){
        if(i>z){ans*=2;break;}
        ll int c=1;
        while(b%i==0){b/=i;c++;z=sqrt(b);}
        ans*=c;
        if(b==1)break;
    }
    pf("%I64d",ans);
}