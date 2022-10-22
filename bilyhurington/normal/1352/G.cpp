/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-09 23:00:44
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
int T,n;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n<=3){printf("-1\n");continue;}
        if(n==4){printf("3 1 4 2\n");continue;}
        if(n%2){
            for(int i=1;i<=n;i+=2) printf("%d ",i);
            printf("%d %d ",n-3,n-1);
            for(int i=n-5;i>=1;i-=2) printf("%d ",i);
            printf("\n");
        }
        else{
            for(int i=1;i<=n;i+=2) printf("%d ",i);
            printf("%d %d %d ",n-4,n,n-2);
            for(int i=n-6;i>=1;i-=2) printf("%d ",i);
            printf("\n");
        }
    }
    return 0;
}