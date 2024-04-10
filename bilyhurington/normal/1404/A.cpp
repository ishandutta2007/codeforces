/*
 * @Author: BilyHurington
 * @Date: 2020-09-06 22:35:02
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-06 22:45:21
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
int T,n,k,a[300010];char s[300010];
void solve(){
    scanf("%d %d %s",&n,&k,s+1);
    for(int i=0;i<k;i++) a[i]=-1;
    for(int i=1;i<=n;i++){
        if(s[i]=='?') continue;
        int x=s[i]-'0';
        if(a[i%k]>=0&&a[i%k]!=x){puts("NO");return;}
        a[i%k]=x;
    } 
    int cnt[2]={0,0};
    for(int i=0;i<k;i++) if(a[i]>=0) cnt[a[i]]++;
    if(cnt[0]<=k/2&&cnt[1]<=k/2) puts("YES");
    else puts("NO");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}