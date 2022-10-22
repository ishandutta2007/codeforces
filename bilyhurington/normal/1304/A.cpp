/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-13 19:21:04
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
int t,x,y,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&x,&y,&a,&b);
        if((y-x)%(a+b)==0) printf("%d\n",(y-x)/(a+b));
        else printf("-1\n");
    }
    return 0;
}