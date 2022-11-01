#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,d;
    cin >> n >> k >> d;
    vector<int> v[n+1];
    vector<array<int,2>> edges(n-1);
    vector<int> c(n+1,0);
    queue<int> q;
    int id=1;
    for(int i=0;i<k;i++)
    {
        int a;
        cin >> a;
        if(c[a]==0)
        {
            c[a]=id++;
            q.push(a);
        }
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        edges[i]={a,b};
    }
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a])
        {
            if(c[to]==0)
            {
                c[to]=c[a];
                q.push(to);
            }
        }
    }
    cout << id-2 << "\n";
    for(int i=0;i<n-1;i++)
    {
        auto [a,b]=edges[i];
        if(c[a]!=c[b]) cout << i+1 << " ";
    }
    cout << "\n";
    return 0;
}