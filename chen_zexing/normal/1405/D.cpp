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
vector <int> v[100005];
int d[100005];
void dfs(int x,int from){
    d[x]=d[from]+1;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from)
            dfs(v[x][i],x);
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,a,b,da,db;
        cin>>n>>a>>b>>da>>db;
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(da*2>=db){
            puts("Alice");
            continue;
        }
        d[0]=-1;
        dfs(a,0);
        if(d[b]<=da){
            puts("Alice");
            continue;
        }
        int mx=0,p=-1;
        for(int i=1;i<=n;i++){
            if(mx<d[i]){
                p=i;
                mx=d[i];
            }
        }
        dfs(p,0);
        mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,d[i]);
        if(mx<=da*2){
            puts("Alice");
            continue;
        }
        puts("Bob");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp