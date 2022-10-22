/*
 * @Author: BilyHurington
 * @Date: 2020-10-17 21:05:04
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-17 21:09:52
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
int T,x1,y1,x2,y2;
void solve(){
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int ans=abs(y2-y1)+abs(x2-x1);
    if(x1==x2||y1==y2) printf("%d\n",ans);
    else printf("%d\n",ans+2);
    
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}