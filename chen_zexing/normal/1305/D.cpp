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
vector <int> v[1005];
int st,sz[1005],mx,n,vis[1005],dep[1005],now=INT_MAX;
void dfs(int x,int from){
    sz[x]=1;
    dep[x]=dep[from]+1;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from){
            dfs(v[x][i],x);
            sz[x]+=sz[v[x][i]];
        }
    mx=max(mx,dep[x]);
}
int solve(int x){
    vector <int> link;
    link.push_back(1);
    for(int i=0;i<v[x].size();i++)
        if(!vis[v[x][i]])
            link.push_back(v[x][i]);
    //cout<<x<<" "<<link.size()<<endl;
    if(link.size()==1) return x;
    if(link.size()==2){
        printf("? %d %d\n",link[1],x);
        fflush(stdout);
        int t;
        scanf("%d",&t);
        if(t==x) return x;
        else {
            vis[x]=1;
            return solve(t);
        }
    }
    int t;
    for(int i=1;i<link.size()-1;i+=2) {
        printf("? %d %d\n",link[i],link[i+1]);
        fflush(stdout);
        scanf("%d",&t);
        if(t==link[i]||t==link[i+1]){
            vis[x]=1;
            return solve(t);
        }
        else{
            vis[link[i]]=vis[link[i+1]]=1;
        }
    }
    if(link.size()%2==0){
        return solve(link[link.size()-1]);
    }
    else return x;
}
int main() {
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        mx=0;
        dfs(i,0);
        if(mx<now) now=mx,st=i;
    }
    //cout<<st<<endl;
    printf("! %d\n",solve(st));
    return 0;
}