#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
vector <int> v[200005];
long long l[200005],r[200005],dp[200005][2];
void dfs(int x,int from){
    dp[x][0]=dp[x][1]=0;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from){
            dfs(v[x][i],x);
            dp[x][0]+=max(abs(l[v[x][i]]-l[x])+dp[v[x][i]][0],abs(r[v[x][i]]-l[x])+dp[v[x][i]][1]);
            dp[x][1]+=max(abs(l[v[x][i]]-r[x])+dp[v[x][i]][0],abs(r[v[x][i]]-r[x])+dp[v[x][i]][1]);
        }
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            v[i].clear();
            scanf("%lld%lld",&l[i],&r[i]);
        }
        for(int i=1,x,y;i<n;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp