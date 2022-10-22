#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, q, m, a[200005], t[200005], l[200005], r[200005], b[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<q; i++)
        cin >> t[i] >> l[i] >> r[i];

    for(int i=0; i<m; i++)
        cin >> b[i];

    for(int i=0; i<m; i++)
    {
        for(int j = q - 1; j >= 0; j--)
        {
            if(t[j] == 1)
            {
                if(b[i] > l[j] && b[i] <= r[j])
                    b[i]--;
                else if(b[i] == l[j])
                    b[i] = r[j];
            }
            else
            {
                if(b[i] >= l[j] && b[i] <= r[j])
                    b[i] = l[j] + r[j] - b[i];
            }
        }

        cout << a[b[i] - 1] << ' ';
    }
}