#include<stdio.h>
#include<algorithm>
using namespace std;
main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,X,a[128],an=0,i;
    scanf("%d%d",&n,&X);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]*=n-i;
    }
    sort(a,a+n);
    for(i=0;i<n&&X>=a[i];i++){
        X-=a[i];
        an++;
    }
    printf("%d\n",an);
}