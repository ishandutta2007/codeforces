#include<stdio.h>
#include<algorithm>
using namespace std;
int an[1024][1024];
main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        k=i;
        for(j=0;j<n-1;j++){
            an[i-1][j]=k++;
            if(k==n)k=1;
        }
    }
    for(i=0;i<n-1;i++)swap(an[i][i],an[i][n-1]);
    for(i=0;i<n;i++)an[n-1][i]=an[i][n-1];
    for(i=0;i<n;i++,puts("")){
        printf("%d",an[i][0]);
        for(j=1;j<n;j++)printf(" %d",an[i][j]);
    }
}