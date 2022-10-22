/*
 * @Author: BilyHurington
 * @Date: 2020-10-17 21:05:04
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-17 21:14:30
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
int T,n;char s[300010];
void solve(){
    scanf("%d %s",&n,s);
    bool tag1=1,tag2=1;
    for(int i=0;i<n;i++){
        if(s[i]=='<') tag1=0;
        if(s[i]=='>') tag2=0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='-'||s[(i+1)%n]=='-') ans++;
        else ans+=tag1||tag2;
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}