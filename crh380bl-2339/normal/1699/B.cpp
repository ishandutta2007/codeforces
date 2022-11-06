#include<bits/stdc++.h>
using namespace std;
int a[4][4];
int b[100][100];
int main(){
    int t,n,m,i,j;
    memset(a,0,sizeof(a));
    a[0][0]=a[3][0]=a[0][3]=a[3][3]=1;
    a[1][1]=a[1][2]=a[2][1]=a[2][2]=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;++i){
            for(j=0;j<m;++j)printf("%d ",a[i%4][j%4]);
            puts("");
        }
    }
    return 0;
}