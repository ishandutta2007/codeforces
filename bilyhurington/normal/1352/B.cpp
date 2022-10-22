/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-09 23:16:58
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
int T,n,k;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        if(k>n||(k%2==0&&n%2==1)||(k%2==1&&n%2==0&&2*k>n)){printf("NO\n");continue;}
        printf("YES\n");
        if(k%2==1&&n%2==0){
            for(int i=1;i<k;i++) printf("2 "),n-=2;
            printf("%d\n",n);
        }
        else{
            for(int i=1;i<k;i++) printf("1 "),n--;
            printf("%d\n",n);
        }
    }
    return 0;
}