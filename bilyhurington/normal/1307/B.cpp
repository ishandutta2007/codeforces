/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-17 23:51:27
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
int T,n,x,a[100010];
int main(){
    scanf("%d",&T);
    while(T--){
        bool pd=0;
        scanf("%d %d",&n,&x);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(x==a[i]) pd=1;
        }
        if(pd){
            printf("1\n");
            continue;
        }
        sort(a+1,a+n+1);
        int ans=(x+a[n]-1)/a[n];
        ans=max(ans,2);
        printf("%d\n",ans);
    }
    return 0;
}