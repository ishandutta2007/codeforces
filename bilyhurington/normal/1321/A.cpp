/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-01 21:21:11
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
int n,a[110],b[110];
int main(){
    scanf("%d",&n);
    bool pd=1;
    int cnta=0,cntb=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        if(a[i]&&!b[i]) pd=0,cnta++;
        if(!a[i]&&b[i]) cntb++;
    }
    if(pd){printf("-1\n");return 0;}
    printf("%d\n",max(1,(int)ceil((double)(cntb+1)/cnta)));
    return 0;
}