#include<stdio.h>
#include<algorithm>
using namespace std;
int a[512],b[512],an[1000000];
main(){
    int n,i,j,m=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(j=1;j<=n;j++)
        scanf("%d",&b[j]);
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++)
            if(a[i]==b[j])break;
        for(j--;j>=i;j--){
            swap(b[j],b[j+1]);
            an[m++]=j;
        }
    }
    printf("%d\n",m);
    for(i=0;i<m;i++)printf("%d %d\n",an[i],an[i]+1);
}