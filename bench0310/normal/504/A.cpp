#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> d(n,0);
    vector<int> s(n,0);
    for(int i=0;i<n;i++) cin >> d[i] >> s[i];
    queue<int> q;
    for(int i=0;i<n;i++) if(d[i]==1) q.push(i);
    vector<array<int,2>> edges;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        if(d[a]==0) continue;
        int b=s[a];
        edges.push_back({a,b});
        d[b]--;
        s[b]^=a;
        if(d[b]==1) q.push(b);
    }
    cout << edges.size() << "\n";
    for(auto [a,b]:edges) cout << a << " " << b << "\n";
    return 0;
}