#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, m, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n * m; i++)
            cin >> a[i];

        map <int, vector <int> > q;
        map <int, int> c;

        for(int i = 0; i < n * m; i++)
        {
            q[a[i]].pb(i);
            c[a[i]]++;
        }

        sort(a, a + n * m);

        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j < m; j++)
            {
                c[a[i * m + j]]--;
                b[i * m + j] = q[a[i * m + j]][c[a[i * m + j]]];
            }

//        cout << "! ";
//
//        for(int i = 0; i < n * m; i++)
//            cout << b[i] << ' ';
//
//        cout << endl;

        int ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < j; k++)
                    if(b[i * m + k] < b[i * m + j])
                        ans++;

        cout << ans << "\n";
    }
}