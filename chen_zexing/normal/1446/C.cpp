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
int son[7000000][2],sz[7000000],x=1,a[200005];
int dfs(int x){
    if(sz[x]==0) return 0;
    if(sz[x]==1) return 1;
    if(sz[son[x][0]]==0) return dfs(son[x][1]);
    if(sz[son[x][1]]==0) return dfs(son[x][0]);
    return 1+max(dfs(son[x][1]),dfs(son[x][0]));
}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int now=1;
        sz[now]++;
        for(int j=30;j>=0;j--){
            int t=((a[i]&(1<<j))>0);
            if(!son[now][t])
                son[now][t]=++x;
            now=son[now][t];
            sz[now]++;
        }
    }
    printf("%d\n",n-dfs(1));
    return 0;
}