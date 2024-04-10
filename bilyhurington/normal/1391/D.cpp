/*
 * @Author: BilyHurington
 * @Date: 2020-08-09 22:35:00
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-09 23:01:05
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
int n,m,a[1000010],f[1000010][8],cnt[8];
int main(){
    scanf("%d %d",&n,&m);
    if(n>=4&&m>=4){printf("-1");return 0;}
    char x;
    if(n>=m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf(" %c",&x);
                a[i]=a[i]*2+x-'0';
            }
            // printf("%d ",a[i]);
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf(" %c",&x);
                a[j]=a[j]*2+x-'0';
            }
        }
        swap(n,m);
    }
    if(m==1){printf("0");return 0;}
    for(int i=1;i<8;i++) cnt[i]=cnt[i-(i&-i)]+1;
    if(m==2){
        // for(int i=1;i<=n;i++) printf("%d ",a[i]);
        for(int i=1;i<=n;i++) for(int j=0;j<4;j++) f[i][j]=2e9;
        for(int i=0;i<4;i++) f[1][i]=cnt[i^a[1]];
        for(int i=2;i<=n;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if((cnt[j]+cnt[k])&1) f[i][k]=min(f[i][k],f[i-1][j]+cnt[k^a[i]]);
                }
            }
        }
        int minn=2e9;
        for(int i=0;i<4;i++) minn=min(minn,f[n][i]);
        if(minn>1e9) printf("-1");
        else printf("%d",minn);
    }
    else{
        for(int i=1;i<=n;i++) for(int j=0;j<8;j++) f[i][j]=2e9;
        for(int i=0;i<8;i++) f[1][i]=cnt[i^a[1]];
        for(int i=2;i<=n;i++){
            for(int j=0;j<8;j++){
                for(int k=0;k<8;k++){
                    if(((cnt[j&3]+cnt[k&3])&1)&&((cnt[j>>1]+cnt[k>>1])&1)) f[i][k]=min(f[i][k],f[i-1][j]+cnt[k^a[i]]);
                }
            }
        }
        int minn=2e9;
        for(int i=0;i<8;i++) minn=min(minn,f[n][i]);
        if(minn>1e9) printf("-1");
        else printf("%d",minn);
    }
    return 0;
}