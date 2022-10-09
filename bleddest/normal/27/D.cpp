#include<bits/stdc++.h>

using namespace std;

int main()
{
    int v, n;
    cin >> v >> n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    vector<vector<int>> g(n);
    
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            set<int> s = {l[i], r[i], l[j], r[j]};
            if(s.size() < 4)
                continue;
            vector<pair<int, int>> v = {{l[i], 0}, {r[i], 0}, {l[j], 1}, {r[j], 1}};
            sort(v.begin(), v.end());
            bool good = false;
            for(int i = 0; i < 3; i++)
                if(v[i].second == v[i + 1].second)
                    good = true;
            if(!good)
                g[i].push_back(j);
        }
    vector<int> d(n, int(1e9));
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(d[i] == int(1e9))
        {
            d[i] = 0;
            q.push(i);
            while(!q.empty())
            {
                int k = q.front();
                q.pop();
                for(auto y : g[k])
                    if(d[y] > d[k] + 1)
                    {
                        d[y] = d[k] + 1;
                        q.push(y);
                    }
            }
        }
    }
    bool good = true;
    for(int i = 0; i < n; i++)
        for(auto j : g[i])
            if(d[i] % 2 == d[j] % 2)
                good = false;
    if(!good)
        cout << "Impossible" << endl;
    else
    {                         
        for(int i = 0; i < n; i++)
            if(d[i] % 2 == 0)
                cout << "i";
            else
                cout << "o";
        cout << endl;
    }
}