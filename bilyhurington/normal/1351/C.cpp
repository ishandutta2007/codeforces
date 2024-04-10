/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-07 22:24:45
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
int T,n,nxt[5][2]={{},{1,0},{-1,0},{0,1},{0,-1}},t[5][3]={{},{0,0,0},{-1,0,0},{0,0,1},{0,-1,1}};
char s[100010];
map<pair<pair<int,int>,int>,int> mp;
int tr(char ch){
    if(ch=='S') return 1;
    if(ch=='N') return 2;
    if(ch=='W') return 3;
    return 4;
}
int main(){
    scanf("%d",&T);
    while(T--){
        mp.clear();
        scanf("%s",s+1);
        n=strlen(s+1);
        int ans=0;
        for(int i=1,x=0,y=0;i<=n;i++){
            int p=tr(s[i]);
            if(mp[make_pair(make_pair(x+t[p][0],y+t[p][1]),t[p][2])]) ans++;
            else mp[make_pair(make_pair(x+t[p][0],y+t[p][1]),t[p][2])]=1,ans+=5;
            x+=nxt[p][0];y+=nxt[p][1];
        }
        printf("%d\n",ans);
    }
    return 0;
}