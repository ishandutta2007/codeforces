//  228

#include<iostream>
#include<cstdio>
using namespace std;
const int INF=27;

int n,m,sum[INF][INF],ans;
signed main(){
    scanf("%d %d\n",&n,&m);
    for(int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char ch=' ';
            scanf("%c",&ch);
            if(ch=='0')sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            else sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+1;
        }
        scanf("\n");
    }
    for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++)
            for(int x_=x;x_<=n;x_++)
                for(int y_=y;y_<=m;y_++){
                    if((sum[x_][y_]-sum[x_][y-1]-sum[x-1][y_]+sum[x-1][y-1])==0){
                        ans=max(((x_-x+1)+(y_-y+1))*2,ans);
                    }
                }   
    printf("%d\n",ans);
    return 0;
}