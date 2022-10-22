#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string s, t;
int n;

void Sort(int l, int r)
{
    if((r - l) % 2)
        return;

    int m = (l + r) / 2;

    Sort(l, m);
    Sort(m, r);

    if(s.substr(l, m - l) > s.substr(m, r - m))
    {
        for(int i = l; i < m; i++)
            swap(s[i], s[i + m - l]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    n = s.size();

    Sort(0, n);
    swap(s, t);
    Sort(0, n);

    if(s == t)
        cout << "YES";
    else cout << "NO";
}