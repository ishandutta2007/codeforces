/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-09 23:11:27
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
int T,n,a[8010];
bool vis[8010];
deque<int> q;
int main(){
    scanf("%d",&T);
    while(T--){
        q.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),vis[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<q.size();j++) q[j]+=a[i];
            while(!q.empty()&&q.front()>n) q.pop_front();
            for(int j=0;j<q.size();j++) vis[q[j]]=1;
            q.push_back(a[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[a[i]]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}