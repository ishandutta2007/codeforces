#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, p[128], siz[128];
string s, t;
vector <pair <int, int> > v;

int get(int x)
{
    if(x == p[x])
        return x;
    p[x] = get(p[x]);
    return p[x];
}

void unite(int x, int y)
{
    x = get(x);
    y = get(y);
    if(siz[x] > siz[y])
        swap(x, y);
    p[x] = y;
    siz[y] += siz[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<128; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }

    cin >> n >> s >> t;
    for(int i=0; i<n; i++)
    {
        if(get(s[i]) != get(t[i]))
        {
            v.push_back({get(s[i]), get(t[i])});
            unite(s[i], t[i]);
        }
    }

    cout << v.size() << "\n";
    for(auto to:v)
        cout << (char)to.first << ' ' << (char)to.second << "\n";
}