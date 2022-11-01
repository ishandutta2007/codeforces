#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> vr[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        vr[b].push_back({a,c});
    }
    vector<int> rm(n+1,-1);
    vector<int> d(n+1,n);
    d[n]=0;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto [to,c]:vr[a])
        {
            if(rm[to]==-1) rm[to]=c;
            else if(rm[to]!=c&&d[to]>d[a]+1)
            {
                d[to]=d[a]+1;
                q.push(to);
            }
        }
    }
    if(d[1]==n) cout << "-1\n";
    else cout << d[1] << "\n";
    for(int i=1;i<=n;i++) if(rm[i]==-1) rm[i]=0;
    for(int i=1;i<=n;i++) cout << (rm[i]^1);
    cout << "\n";
    return 0;
}