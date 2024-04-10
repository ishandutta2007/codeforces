/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-09 23:21:02
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
        int tmp=(k-1)/(n-1);
        printf("%d\n",tmp*n+k-tmp*(n-1));
    }
    return 0;
}