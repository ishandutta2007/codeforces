#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 1000000
vector<int>e[SIZE];
int d[SIZE],used[SIZE];
int dfs(int x){
    if(used[x])return 0;
    used[x]=1;
    int cnt=1;
    for(int i=0;i<e[x].size();i++)cnt+=dfs(e[x][i]);
    return cnt;
}
bool star(int n){
    int i;
    for(i=1;i<n;i++)
        if(d[i]!=1)return 0;
    return d[n]==n-1;
}
bool ring(int n){
    int i;
    for(i=1;i<=n;i++)
        if(d[n]!=2)return 0;
    return dfs(1)==n;
}
bool bus(int n){
    int i;
    for(i=3;i<=n;i++)
        if(d[i]!=2)return 0;
    for(i=1;i<=2;i++)
        if(d[i]!=1)return 0;
    for(i=1;e[i].size()!=1;i++);
    return dfs(i)==n;
}
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    for(i=1;i<=n;i++)d[i]=e[i].size();
    sort(d+1,d+1+n);
    if(n==m+1){
        if(star(n))puts("star topology");
        else if(bus(n))puts("bus topology");
        else puts("unknown topology");
    }
    else if(n==m){
        if(ring(n))puts("ring topology");
        else puts("unknown topology");
    }
    else puts("unknown topology");
    return 0;
}