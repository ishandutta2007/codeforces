/*
 * @Author: BilyHurington
 * @Date: 2020-10-17 21:05:04
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-17 21:18:58
 */ 
#include<bits/stdc++.h>
using namespace std;
int T,n;char s[200010];
stack<char> S;
void solve(){
    scanf("%s",s+1);n=strlen(s+1);
    while(!S.empty()) S.pop();
    for(int i=1;i<=n;i++){
        if(s[i]=='A') S.push('A');
        else if(S.size()) S.pop();
        else S.push('B');
    }
    printf("%d\n",S.size());
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}