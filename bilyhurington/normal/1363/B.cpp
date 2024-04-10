/*
 * @Author: BilyHurington
 * @Date: 2020-05-31 22:36:40
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-31 22:44:18
 */ 
#include<bits/stdc++.h>
using namespace std;
int T,n,q[1010][2],h[1010][2];
char s[1010];
void solve(){
    scanf("%s",s+1);
    n=strlen(s+1);
    memset(q,0,sizeof(q));
    memset(h,0,sizeof(h));
    for(int i=1;i<=n;i++) q[i][0]=q[i-1][0],q[i][1]=q[i-1][1],q[i][s[i]-'0']++;
    for(int i=n;i>=1;i--) h[i][0]=h[i+1][0],h[i][1]=h[i+1][1],h[i][s[i]-'0']++;
    int ans=2e9;
    for(int i=0;i<=n;i++){
        ans=min(ans,min(q[i][0]+h[i+1][1],q[i][1]+h[i+1][0]));
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}