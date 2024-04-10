#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, y, a[200005], z, t[200005];
map <int, int> m, q, p;

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i <= z; i = (i | i + 1))
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if(m[a] == 0)
            m[a] = a;

        if(m[b] == 0)
            m[b] = b;

        swap(m[a], m[b]);
    }

    for(auto x:m)
    {
        a[y] = x.y;
        q[x.x] = y++;
    }

    int ans = 0;

    for(auto x:m)
        ans += abs(x.x - x.y) - abs(q[x.x] - q[x.y]);

    vector <int> v;

    for(auto x:m)
        v.pb(x.y);

    sort(v.begin(), v.end());

    for(auto x:v)
        p[x] = z++;

//    for(int i = 0; i < y; i++)
//        cout << p[a[i]] << ' ';

//    cout << endl;

    for(int i = y - 1; i >= 0; i--)
    {
        ans += sum(p[a[i]]);
        inc(p[a[i]], 1);
    }

    cout << ans;
}