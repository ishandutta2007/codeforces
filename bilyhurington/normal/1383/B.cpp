/*
 * @Author: BilyHurington
 * @Date: 2020-07-24 22:37:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-25 00:02:28
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
int T,n,a[100010];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=29;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++) cnt+=(a[j]>>i)&1;
        if(cnt%2==0) continue;
        if(cnt<n){
            if(!(n&1)||cnt%4==1){printf("WIN\n");return;}
            else{printf("LOSE\n");return;}
        }
        else{printf(cnt%4==1?"WIN\n":"LOSE\n");return;}
    }
    printf("DRAW\n");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}