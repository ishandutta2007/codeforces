/*
 * @Author: BilyHurington
 * @Date: 2020-07-04 22:45:02
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-04 22:48:14
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
int T,n,a[110];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(i&1) a[i]=abs(a[i]);
        else a[i]=-abs(a[i]);
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}