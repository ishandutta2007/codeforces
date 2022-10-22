#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, t[200005], d[200005], a[200005], y, s[200005], k[200005];
map <int, int> m;
vector <int> v;

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += s[r];

    return ans;
}

void incs(int i, int d)
{
    for(; i < y; i = (i | i + 1))
        s[i] += d;
}

int cnt(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += k[r];

    return ans;
}

void inck(int i, int d)
{
    for(; i < y; i = (i | i + 1))
        k[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        {
            cin >> t[i] >> d[i];

            v.push_back(abs(d[i]));
        }

    y = 1;

    sort(v.rbegin(), v.rend());

    for(auto to:v)
    {
        if(m[to] == 0)
        {
            m[to] = y;
            a[y] = m[to];
            y++;
        }
    }

    set <int> moln, ogn;

    int s = 0;

    for(int i = 0; i < n; i++)
    {
        s += d[i];

        if(t[i] == 0)
        {
            if(d[i] > 0)
            {
                ogn.insert(-d[i]);
                inck(m[d[i]], 1);
                incs(m[d[i]], d[i]);
            }
            else
            {
                ogn.erase(d[i]);
                inck(m[-d[i]], -1);
                incs(m[-d[i]], d[i]);
            }
        }
        else
        {
            if(d[i] > 0)
            {
                moln.insert(d[i]);
                inck(m[d[i]], 1);
                incs(m[d[i]], d[i]);
            }
            else
            {
                moln.erase(-d[i]);
                inck(m[-d[i]], -1);
                incs(m[-d[i]], d[i]);
            }
        }

        int x = moln.size();

        int L = -1;
        int R = y;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(cnt(M) >= x)
                R = M;
            else L = M;
        }

        int z = sum(R);

        if(moln.size() == 0)
            z = 0;
        else
        if(ogn.size() == 0)
            z -= (*moln.begin());
        else
        if(-(*ogn.begin()) < (*moln.begin()))
            z -= ((*moln.begin()) + (*ogn.begin()));

        cout << z + s << "\n";
    }
}