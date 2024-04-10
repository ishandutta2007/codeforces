#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int a[200005],pre[200005],dp[200005];
vector <int> v[200005];
set <int> s[200005];
void dfs(int x,int from){
    pre[x]=pre[from]^a[x];
    for(auto t:v[x]) if(t!=from) dfs(t,x),dp[x]+=dp[t];
    if(a[x]==0){
        dp[x]++;
        return;
    }
    s[x].insert(pre[x]);
    for(auto t:v[x])
        if(t!=from){
            if(s[t].size()>s[x].size()) swap(s[x],s[t]);
            int f=0;
            for(auto val:s[t]){
                if(s[x].find(val^a[x])!=s[x].end()){
                    dp[x]++;
                    s[x].clear();
                    f=1;
                    break;
                }
            }
            if(f) break;
            for(auto val:s[t]) s[x].insert(val);
        }
    //cout<<x<<" "<<dp[x]<<" "<<pre[x]<<endl;
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        dfs(1,0);
        printf("%d\n",dp[1]);
    }
    return 0;
}
//unordered_map
//cf