/*
 * @Author: BilyHurington
 * @Date: 2020-02-12 22:15:13
 * @LastEditors  : BilyHurington
 * @LastEditTime : 2020-02-12 22:50:02
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
int T;
long long n,g,b;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld %lld",&n,&g,&b);
        long long x=(n+1)/2,y=n-x,z;
        printf("%lld\n",max((x-1)/g*(g+b)+x-(x-1)/g*g,n));
    }
    return 0;
}