#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, l[100005], d[100005], k[100005], c[205];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> l[i];

    for(int i = 0; i < n; i++)
        cin >> d[i];

    vector <vector <int> > v;

    for(int i = 0; i < n; i++)
    {
        k[l[i]]++;
        c[d[i]]++;
        v.pb({-l[i], d[i], i});
    }

    sort(v.begin(), v.end());

    int w = 0, ans = 1e18;

    for(int i = 0; i < n;)
    {
        int j = i;

        while(j < n && v[j][0] == v[i][0])
        {
            c[v[j][1]]--;
            j++;
        }

//        cout << i << ' ' << j << endl;

        int p = 0;

        for(int z = 0; z <= 200; z++)
            p += z * c[z];

//        cout << p << endl;

        int x = j - i - 1;

        for(int z = 200; z >= 0; z--)
        {
            int y = min(x, c[z]);
            x -= y;
            p -= y * z;
        }

        ans = min(ans, w + p);

//        cout << "! " << w << ' ' << p << endl;

        for(int z = i; z < j; z++)
            w += v[z][1];

        i = j;
    }

    cout << ans;
}