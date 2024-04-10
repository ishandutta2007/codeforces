/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-06 22:44:11
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
int T,n,a[200010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=i,a[i]=(a[i]%n+n)%n;
        sort(a+1,a+n+1);
        // for(int i=1;i<=n;i++) printf("%d ",a[i]);
        bool pd=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=i-1){
                printf("NO\n");
                pd=0;break;
            }
        }
        if(pd){printf("YES\n");}
    }
    return 0;
}