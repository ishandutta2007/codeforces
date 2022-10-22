#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,a[60][60],b[60][60],ans[100010][2],cnt;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1&&a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1){
                b[i][j]=1,b[i+1][j]=1,b[i][j+1]=1,b[i+1][j+1]=1;
                ans[++cnt][0]=i;
                ans[cnt][1]=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!=b[i][j]){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
}