#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 10000
int a[SIZE];
main(){
    int n,m,k,i,ma=0,mi=1000000000,u;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    if(n%2==0)puts("0");
    else{
        for(i=0;i<n;i++){
            if(i&1)ma=max(ma,a[i]);
            else mi=min(mi,a[i]);
        }
        u=n/2+1;
        m/=u;
        printf("%I64d\n",min((long long)mi,(long long)k*m));
    }
}