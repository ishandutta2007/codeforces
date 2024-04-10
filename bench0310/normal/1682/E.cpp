#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) cin >> p[i];
    vector<int> h(n+1,0);
    int tcnt=0;
    for(int i=1;i<=n;i++)
    {
        if(h[i]!=0) continue;
        int a=i;
        while(h[a]==0)
        {
            h[a]=(++tcnt);
            a=p[a];
        }
    }
    vector<array<int,2>> v[n+1];
    vector<array<int,2>> edges(m+1);
    vector<int> idx(n+1,0);
    for(int i=1;i<=m;i++)
    {
        auto &[a,b]=edges[i];
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        idx[a]++; idx[b]++;
    }
    vector<int> q;
    vector<int> e(m+1,0);
    auto reduce=[&](int a)
    {
        if(idx[a]==0) return;
        if((++e[v[a][--idx[a]][1]])==2) q.push_back(v[a][idx[a]][1]);
    };
    for(int i=1;i<=n;i++)
    {
        auto cmp=[&](array<int,2> a,array<int,2> b)->bool
        {
            int x=a[0],y=b[0];
            if((h[x]>h[i])!=(h[y]>h[i])) return (h[x]>h[i]);
            return (h[x]<h[y]);
        };
        ranges::sort(v[i],cmp);
        reduce(i);
    }
    for(int i=0;i<m;i++)
    {
        int c=q[i];
        auto [a,b]=edges[c];
        reduce(a); reduce(b);
    }
    for(int i=m-1;i>=0;i--) cout << q[i] << " \n"[i==0];
    return 0;
}