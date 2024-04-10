#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, q, ps[100005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> s;

    ps[0] = 0;

    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + s[i] - 'a' + 1;

    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << ps[r] - ps[l - 1] << "\n";
    }
}