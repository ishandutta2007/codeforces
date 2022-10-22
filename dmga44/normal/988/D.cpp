#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

map<int,bool> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,xi;
    cin >> n;
    vector<int> res;
    vector<int> points;
    for(int i=0;i<n;i++)
    {
        cin >> xi;
        points.push_back(xi);
    }

    sort(points.begin(),points.end());

    for(int i=0;i<n;i++)
    {
        xi=points[i];
        m[xi]=1;
        for(int j=0;j<31;j++)
        {
            int v=(1<<j);
            if(m[xi-v])
            {
                if(m[xi-2*v] && res.size()<3)
                    res={xi,xi-v,xi-2*v};
                else if(res.size()<2)
                    res={xi,xi-v};
            }
            if(res.empty())
                res.push_back(xi);
        }
    }
    db(res.size())
    for(auto v : res)
        cout << v << ' ';

    return 0;
}