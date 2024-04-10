/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-19 22:40:49
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
        if(n==1){printf("-1\n");continue;}
        if(n%3!=1){
            for(int i=1;i<n;i++) printf("2");
            printf("3\n");
        }
        else{
            for(int i=1;i<n-1;i++) printf("2");
            printf("33\n");
        }
    }
    return 0;
}