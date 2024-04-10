/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-26 22:38:44
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
int T,x,y,a,b;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d",&x,&y,&a,&b);
        if(2*a<=b){printf("%lld\n",a*(long long)(x+y));continue;}
        if(x>y) swap(x,y);
        printf("%lld\n",(long long)x*b+(y-x)*(long long)a);
    }
    return 0;
}