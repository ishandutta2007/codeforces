/*
 * @Author: BilyHurington
 * @Date: 2020-07-04 22:45:02
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-04 23:49:21
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
int T,n,a[300010];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(a[1]<a[n]) printf("YES\n");
    else printf("NO\n");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}