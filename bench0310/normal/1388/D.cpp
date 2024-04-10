#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> b(n+1,0);
    vector<int> in(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
        if(b[i]!=-1) in[b[i]]++;
    }
    queue<int> t;
    for(int i=1;i<=n;i++) if(in[i]==0) t.push(i);
    vector<int> ord(n+1,0);
    vector<int> rev(n+1,0);
    int tcnt=1;
    for(int i=1;i<=n;i++)
    {
        int e=t.front();
        t.pop();
        ord[e]=tcnt;
        rev[tcnt++]=e;
        if(b[e]!=-1)
        {
            in[b[e]]--;
            if(in[b[e]]==0) t.push(b[e]);
        }
    }
    ll res=0;
    vector<int> x;
    vector<bool> vis(n+1,0);
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
    for(int i=1;i<=n;i++) if(a[i]>0) q.push({ord[i],i});
    while(!q.empty())
    {
        int e=q.top()[1];
        q.pop();
        res+=a[e];
        x.push_back(e);
        vis[e]=1;
        if(b[e]!=-1)
        {
            if(a[b[e]]<=0&&a[b[e]]+a[e]>0) q.push({ord[b[e]],b[e]});
            a[b[e]]+=a[e];
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(vis[rev[i]]==0)
        {
            res+=a[rev[i]];
            x.push_back(rev[i]);
        }
    }
    cout << res << "\n";
    for(int i=0;i<n;i++) cout << x[i] << " \n"[i==n-1];
    return 0;
}