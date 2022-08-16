#include <stdio.h>
#include <string.h>
#define ll long long
#define pf printf
#define sf scanf
#define ron(i,n) for(int i=0;i<n;i++)
#define pfd(a) printf("%d",a)
#define sfd(a) scanf("%d",&a)
int main(){
    ll int n,m,k,l;
    sf("%I64d %I64d %I64d %I64d",&n,&m,&k,&l);
    if((m>n)||(l+k>n))goto no;

    ll int d=(l+k)/m;
    if(m*d-k<l)d++;
    if(m*d>n)goto no;
    pf("%I64d",d);
    return 0;
    no: pfd(-1);
}