#include <cstdio>
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
int l[200005],r[200005];
vector <int> v[200005];
int dp[200005];
long long tot[200005];
void dfs(int x){
    long long can=0,sum=0;
    for(auto t:v[x]) dfs(t),can+=tot[t],sum+=dp[t];
    if(can>r[x]) dp[x]=sum,tot[x]=r[x];
    else if(can>=l[x]) dp[x]=sum,tot[x]=can;
    else dp[x]=sum+1,tot[x]=r[x];
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=2,x;i<=n;i++) scanf("%d",&x),v[x].push_back(i);
        for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
        dfs(1);
        printf("%d\n",dp[1]);
    }
    return 0;
}