#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
set <int> s;
int fa[100005],sz[100005],cnt[100005];
vector <int> v[100005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        int ans=n-1;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        s.insert(1);
        for(int i=2;i<=n;i++){
            for(int j=0;j<v[i].size();j++) cnt[find(v[i][j])]++;
            for(auto it=s.begin();it!=s.end();){
                if(cnt[*it]<sz[*it]) fa[*it]=i,sz[i]+=sz[*it],s.erase(it++),ans--;
                else it++;
            }
            for(int j=0;j<v[i].size();j++) cnt[find(v[i][j])]=0;
            s.insert(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp