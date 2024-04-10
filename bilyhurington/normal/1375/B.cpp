/*
 * @Author: BilyHurington
 * @Date: 2020-07-04 22:45:02
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-04 22:57:56
 */ 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,n,m,a[310][310],b[310][310],nxt[5][2]={{},{0,1},{0,-1},{1,0},{-1,0}};
void solve(){
    scanf("%d %d",&n,&m);
    bool tag=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            int cnt=0;
            for(int k=1;k<=4;k++){
                int nx=i+nxt[k][0],ny=j+nxt[k][1];
                if(nx<=n&&nx>=1&&ny<=m&&ny>=1) cnt++;
            }
            if(cnt<a[i][j]) tag=0;
            b[i][j]=cnt;
        }
    }
    if(!tag){printf("NO\n");return;}
    printf("YES\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%d ",b[i][j]);
        printf("\n");
    }
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}