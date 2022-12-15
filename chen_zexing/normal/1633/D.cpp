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
using namespace std;
vector <int> v[1005];
int d[1005],b[1005],c[1005],p[1005];
int dp[12005];
int main() {
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=i;j++)
            if(i+i/j<=1000) v[i].push_back(i+i/j);
    queue <int> q;
    q.push(1);
    for(int i=1;i<=1000;i++) d[i]=INT_MAX;
    d[1]=0;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto t:v[temp]) if(d[t]==INT_MAX) d[t]=d[temp]+1,q.push(t);
    }
    int T = 1;
    cin >> T;
    while (T--) {
        int n,k,ans=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=1;i<=n;i++) p[i]=d[b[i]];
        for(int i=0;i<=12000;i++) dp[i]=0;
        for(int i=1;i<=n;i++)
            for(int j=12000;j>=p[i];j--)
                dp[j]=max(dp[j],dp[j-p[i]]+c[i]);
        for(int i=0;i<=min(12000,k);i++) ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}