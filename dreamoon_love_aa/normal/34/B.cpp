#include<stdio.h>
#include<algorithm>
using namespace std;
int a[111];
main(){
    int n,m,i,an=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=0;i<m;i++)
        if(a[i]<0)an-=a[i];
    printf("%d\n",an);
}