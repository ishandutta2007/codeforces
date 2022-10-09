#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pt;
#define x first
#define y second

pt operator +(const pt& a, const pt& b)
{
    return {a.x + b.x, a.y + b.y};
}

vector<pt> transitions(const pt& a)
{
    vector<pt> ans;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            ans.push_back(a + pt(i, j));
    return ans;
}

pt ts[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

vector<pt> transitions2(const pt& a)
{
    vector<pt> ans;
    for(int i = 0; i < 8; i++)
        ans.push_back(a + ts[i]);
    return ans;
}

int main()
{
    pt s, t;
    cin >> s.x >> s.y >> t.x >> t.y;
    set<pt> allowed;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int r, a, b;
        cin >> r >> a >> b;
        for(int j = a; j <= b; j++)
            allowed.insert({r, j});
    }
    map<pt, int> d;
    d[s] = 0;
    queue<pt> q;
    q.push(s);
    while(!q.empty())
    {
        pt v = q.front();
        q.pop();
        vector<pt> t = transitions2(v);
        for(auto u : t)
            if(allowed.count(u) && !d.count(u))
            {
                d[u] = d[v] + 1;
                q.push(u);
            }
    }
    if(!d.count(t))
        cout << -1 << endl;
    else
        cout << d[t] << endl;
}