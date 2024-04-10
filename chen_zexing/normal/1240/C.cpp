#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
long long dp[500005][2];
int n,k;
struct edge{
    int ed,w;
};
vector <edge> v[500005];
void dfs(int x,int from){
    if(v[x].size()==1&&x!=1){
        dp[x][0]=dp[x][1]=0;
        return;
    }
    vector <long long> temp;
    long long now=0;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i].ed!=from)
            dfs(v[x][i].ed,x),temp.push_back(dp[v[x][i].ed][1]+v[x][i].w-dp[v[x][i].ed][0]),now+=dp[v[x][i].ed][0];
    sort(temp.begin(),temp.end(),greater<int>());
    for(int i=0;i<temp.size()&&i<k-1;i++)
        if(temp[i]>0) now+=temp[i];
    dp[x][1]=now;
    if(k-1<temp.size()&&temp[k-1]>0) now+=temp[k-1];
    dp[x][0]=now;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1,x,y,w;i<n;i++){
            scanf("%d%d%d",&x,&y,&w);
            v[x].push_back(edge{y,w});
            v[y].push_back(edge{x,w});
        }
        dfs(1,0);
        printf("%lld\n",dp[1][0]);
    }
    return 0;
}
//
/// 
//01
//