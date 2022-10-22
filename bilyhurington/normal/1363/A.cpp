/*
 * @Author: BilyHurington
 * @Date: 2020-05-31 22:36:40
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-31 22:40:13
 */ 
#include<bits/stdc++.h>
using namespace std;
int T,n,k;
void solve(){
    int num[2]={0,0};
    scanf("%d %d",&n,&k);
    for(int i=1,x;i<=n;i++) scanf("%d",&x),num[x%2]++;
    bool tag=0;
    for(int i=0;i<=k;i++){
        int j=k-i;
        if(i<=num[0]&&j<=num[1]&&j%2==1) tag=1; 
    }
    if(tag) printf("Yes\n");
    else printf("No\n");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}