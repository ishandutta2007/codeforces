#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int t,n;
long long edge[100005],mod=1000000007;
int prime[60005];
vector <int> v[100005];
bool cmp(long long a,long long b)
{
    return a>b;
}
int search(int x,int from) {
    int ans = 1;
    for (int i = 0; i < v[x].size(); i++)
        if (v[x][i] != from)
            ans += search(v[x][i], x);
    edge[++t]=1LL*ans*(n-ans);
    return ans;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long ans=0;
        int x, y, a, b;
        cin >> n;
        for(int i=1;i<=n;i++) v[i].clear();
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &x, &y);
            if (i == 1) {
                a = x;
                b = y;
            }
            v[x].push_back(y);
            v[y].push_back(x);
        }
        t = 0;
        search(a,b);
        for(int i=0;i<v[b].size();i++)
            if(v[b][i]!=a)
                search(v[b][i],b);
        sort(edge+1,edge+t+1,cmp);
        for(int i=1;i<=t;i++) edge[i]%=mod;
        int m;
        cin>>m;
        for(int i=1;i<=m;i++) scanf("%d",&prime[i]);
        sort(prime+1,prime+m+1,cmp);
        if(m>=n-1)
        {
            ans=edge[1];
            for(int i=1;i<=m-n+2;i++) ans=ans*prime[i]%mod;
            for(int i=2;i<n;i++) ans=(ans+1LL*prime[i+m-n+1]*edge[i])%mod;
            printf("%lld\n",ans);
        }
        else{
            ans=0;
            for(int i=1;i<=m;i++) ans=(ans+1LL*prime[i]*edge[i])%mod;
            for(int i=m+1;i<n;i++) ans=(ans+edge[i])%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}