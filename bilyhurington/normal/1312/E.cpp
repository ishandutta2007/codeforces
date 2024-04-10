/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-10 00:07:47
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
int n,a[510],f[510][510],g[510];
int main(){
    scanf("%d",&n);
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i][i]=a[i];
    for(int len=1;len<n;len++){
        for(int i=1;i+len<=n;i++){
            int l=i,r=i+len;
            for(int j=l;j<r;j++){
                if(f[l][j]!=-1&&f[l][j]==f[j+1][r]){
                    f[l][r]=f[l][j]+1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        g[i]=g[i-1];
        for(int j=0;j<i;j++) if(f[j+1][i]>=0) g[i]=max(g[i],g[j]+(i-j)-1);
    }
    printf("%d\n",n-g[n]);
    return 0;
}