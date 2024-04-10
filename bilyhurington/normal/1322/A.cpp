/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-07 17:54:29
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
int n;
char s[1000010];
int main(){
    scanf("%d",&n);
    int cnt=0,ans=0;
    for(int l=1,i=1;i<=n;i++){
        scanf(" %c",&s[i]);
        if(s[i]=='('){
            cnt++;
            if(cnt==0) ans+=i-l+1;
        }
        else cnt--; 
        if(cnt==0) l=i+1;
    }
    if(cnt) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}