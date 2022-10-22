/*
 * @Author: BilyHurington
 * @Date: 2020-04-23 22:45:12
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-23 23:04:53
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
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int tot=n;
        bool pd=1;
        for(int i=1;i<=n;i++){
            int j=i;
            while(i<=n&&a[i+1]==a[i]+1) i++;
            if(i>n) break;
            if(a[i]!=tot){pd=0;break;}
            tot=a[j]-1;
        }
        if(pd) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}