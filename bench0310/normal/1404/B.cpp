#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
int n;
vector<int> v[N];

vector<int> bfs(int src)
{
    vector<int> d(n+1,-1);
    queue<int> q;
    q.push(src);
    d[src]=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a])
        {
            if(d[to]==-1)
            {
                d[to]=d[a]+1;
                q.push(to);
            }
        }
    }
    return d;
}

int diameter()
{
    vector<int> d=bfs(1);
    int x=1;
    for(int i=1;i<=n;i++) if(d[i]>d[x]) x=i;
    d=bfs(x);
    int m=d[1];
    for(int i=1;i<=n;i++) m=max(m,d[i]);
    return m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a,b,da,db;
        cin >> a >> b >> da >> db;
        for(int i=0;i<n-1;i++)
        {
            int e,f;
            cin >> e >> f;
            v[e].push_back(f);
            v[f].push_back(e);
        }
        bool alice=0;
        if(2*da>=db) alice=1;
        if(bfs(a)[b]<=da) alice=1;
        if(diameter()<=2*da) alice=1;
        if(alice) cout << "Alice\n";
        else cout << "Bob\n";
        for(int i=1;i<=n;i++) v[i].clear();
    }
    return 0;
}