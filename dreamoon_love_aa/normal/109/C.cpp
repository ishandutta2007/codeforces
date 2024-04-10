#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define SIZE 100001
using namespace std;
set<int>hash;
vector<int>e[SIZE];
bool used[SIZE];
long long an;
int bfs[SIZE],n;
void dfs(long long x){
    if(x>=1000000000)return;
    if(x)hash.insert((int)x);
    dfs(x*10+4);
    dfs(x*10+7);
}
void Go(int x){
    int i,j,k;
    bfs[0]=x;
    used[x]=1;
    for(i=0,j=1;i<j;i++){
        for(k=0;k<e[bfs[i]].size();k++){
            if(!used[e[bfs[i]][k]]){
                used[e[bfs[i]][k]]=1;
                bfs[j++]=e[bfs[i]][k];
            }
        }
    }
    an+=(long long)i*(n-i)*(n-i-1);
}
main(){
    int i,x,y,v;
    dfs(0);
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d%d",&x,&y,&v);
        if(!hash.count(v)){
            e[x].push_back(y);
            e[y].push_back(x);
        }
    }
    for(i=1;i<=n;i++){
        if(!used[i])Go(i);
    }
    cout<<an<<endl;
}