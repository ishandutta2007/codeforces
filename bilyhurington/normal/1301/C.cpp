/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 22:32:42
 * @LastEditors  : BilyHurington
 * @LastEditTime : 2020-02-13 23:00:20
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
long long T,n,m;
int main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld %lld",&n,&m);
        long long num=(n-m)/(m+1),y=n-m-num*(m+1),x=m+1-y;
        long long ans=num*(num+1)/2*x+(num+1)*(num+2)/2*y;
        printf("%lld\n",n*(n+1)/2-ans);
    }
    return 0;
}