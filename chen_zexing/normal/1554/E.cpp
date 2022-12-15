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
#define li __int128_t
using namespace std;
vector <int> v[100005];
int ans[100005];
long long mod=998244353;
int dfs(int x,int from,int ck){
    int temp=v[x].size();
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from){
            int t=dfs(v[x][i],x,ck);
            if(t==-1) return -1;
            if(t) temp--;
        }
    if(temp%ck==0) return 1;
    else if((temp-1+ck)%ck==0) return 0;
    else return -1;
}
long long qpow(long long a,long long b){
    long long ans=1;
    while(b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear(),ans[i]=0;
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        int tot=0;
        for(int i=n-1;i>=2;i--){
            if((n-1)%i) continue;
            if(dfs(1,0,i)==1) ans[i]=1;
            for(int j=i*2;j<=n;j+=i) ans[i]-=ans[j];
            tot+=ans[i];
        }
        ans[1]=((qpow(2,n-1)-tot)+mod)%mod;
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//!