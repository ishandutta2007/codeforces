/*
 * @Author: BilyHurington
 * @Date: 2020-03-09 22:36:53
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-09 22:38:04
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
int T,n,m;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        if(n%m==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}