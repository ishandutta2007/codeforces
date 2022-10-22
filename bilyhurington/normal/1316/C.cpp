/*
 * @Author: BilyHurington
 * @Date: 2020-03-04 22:39:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-04 23:27:41
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
int n,m,mod;
long long ans[2000010],a[1000010],b[1000010];
int main(){
    scanf("%d %d %d",&n,&m,&mod);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<m;i++) scanf("%lld",&b[i]);
    int x,y;
    for(x=0;x<n;x++) if(a[x]%mod) break;
    for(y=0;y<m;y++) if(b[y]%mod) break;
    printf("%d",x+y);
    return 0;
}