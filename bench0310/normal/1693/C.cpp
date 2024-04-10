#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> out(n+1,0);
    vector<int> vr[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        vr[b].push_back(a);
        out[a]++;
    }
    vector<int> d(n+1,(1<<30));
    priority_queue<array<int,2>,vector<array<int,2>>,greater<>> q;
    auto upd=[&](int a,int nd)
    {
        if(nd<d[a])
        {
            d[a]=nd;
            q.push({d[a],a});
        }
    };
    upd(n,0);
    while(!q.empty())
    {
        auto [da,a]=q.top();
        q.pop();
        if(d[a]<da) continue;
        for(int b:vr[a]) upd(b,d[a]+1+(--out[b]));
    }
    cout << d[1] << "\n";
    return 0;
}