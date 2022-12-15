#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
vector <int> v[200005];
long long p[200005],cnt[200005],tot[200005],n;
long long dfs(int x){
    if(v[x].size()==0){
        cnt[x]=1;
        tot[x]=p[x];
        return p[x];
    }
    long long mx=0;
    tot[x]=p[x];
    for(int i=0;i<v[x].size();i++){
        mx=max(mx,dfs(v[x][i]));
        cnt[x]+=cnt[v[x][i]];
        tot[x]+=tot[v[x][i]];
    }
    if(tot[x]<=cnt[x]*mx) return mx;
    else{
        long long t=tot[x]-cnt[x]*mx;
        return mx+t/cnt[x]+(t%cnt[x]>0);
    }
}
int main() {
    int t;
    cin>>n;
    for(int i=2;i<=n;i++) scanf("%d",&t),v[t].push_back(i);
    for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
    printf("%lld\n",dfs(1));
    return 0;
}