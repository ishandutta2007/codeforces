/*
 * @Author: BilyHurington
 * @Date: 2021-02-28 22:15:06
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-02-28 22:18:22
 */
#include<bits/stdc++.h>
using namespace std;
int Q,u,v,su[35],sv[35];
void solve(){
    scanf("%d %d",&u,&v);
    if(v<u){puts("NO");return;}
    for(int i=0;i<=30;i++) su[i]=(u>>i)&1;
    for(int i=0;i<=30;i++) sv[i]=(v>>i)&1;
    int cntu=0,cntv=0;
    for(int i=0;i<=30;i++){
        cntu+=su[i];cntv+=sv[i];
        if(cntv>cntu){puts("NO");return;}
    }
    puts("YES");
}
int main(){
    scanf("%d",&Q);
    while(Q--) solve();
    return 0;
}