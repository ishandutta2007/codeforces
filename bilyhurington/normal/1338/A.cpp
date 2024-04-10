/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-12 22:11:32
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
int T,n,a[100010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        a[0]=-2e9;
        int maxn=0,ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]<a[i-1]) maxn=max(maxn,a[i-1]-a[i]),a[i]=a[i-1];
        }
        while(maxn) ans++,maxn>>=1;
        printf("%d\n",ans);
    }
    return 0;
}