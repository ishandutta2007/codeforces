#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
vector <int> v[100005];
int sz[100005],n,p[100005];
int dfs(int x,int f){
    int mx=0,cnt=1;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]!=f){
            int t=dfs(v[x][i],x);
            mx=max(mx,t);
            if(mx==t) p[x]=v[x][i];
            cnt+=t;
        }
    }
    sz[x]=max(mx,n-cnt);
    if(mx>=n-cnt) p[x]=f;
    return cnt;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int x,y,c,d,mx=INT_MAX,p1=0,p2=0;
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            if(i==1) c=x,d=y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(c,d);
        dfs(d,c);
        for(int i=1;i<=n;i++){
            if(sz[i]<mx){
                mx=sz[i];
                p1=i;
            }
            else if(sz[i]==mx) p2=i;
        }
        if(sz[p1]!=sz[p2]){
            printf("%d %d\n",c,d);
            printf("%d %d\n",d,c);
        }
        else{
            printf("%d %d\n",p1,p[p1]);
            printf("%d %d\n",p2,p[p1]);
        }
    }
    return 0;
}