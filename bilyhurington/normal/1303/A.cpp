/*
 * @Author: BilyHurington
 * @Date: 2020-02-12 22:15:02
 * @LastEditors  : BilyHurington
 * @LastEditTime : 2020-02-12 22:41:07
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
int t,n;
char s[110];
int calc(int l,int r){
    if(l==0) return 0;
    int cnt=0;
    for(int i=l;i<=r;i++){
        if(s[i]=='0') cnt++;
    }
    return cnt;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        n=strlen(s+1);
        s[n+1]=1;
        int ans=0;
        for(int i=1,j=0;i<=n+1;i++){
            if(s[i]=='1'){
                ans+=calc(j,i);
                j=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}