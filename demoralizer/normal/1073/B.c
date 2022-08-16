#include <stdio.h>
#include <string.h>
#include <math.h>
#define lli long long int
#define sf scanf
#define pf printf
int main(){
    int n,t,m=-1;
    sf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) {sf("%d",&t);a[t]=i;}

    for(int i=0;i<n;i++){
        sf("%d",&t);
        if(a[t]<=m)pf("0 ");
        else {pf("%d ",a[t]-m);m=a[t];}
    }

}