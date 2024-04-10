#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(2 * n);

    for(int i = 0; i < 2 * n; i++)
        cin >> a[i];

    vector <int> b(105);

    for(int i = 0; i < 2 * n; i++)
        b[a[i]]++;

    int k1 = 0, k2 = 0, nk1 = 0;

    for(int i = 0; i < 105; i++)
    {
        if(b[i] == 1)
            k1++;

        if(b[i] > 1)
            k2++;
    }

    vector <int> used(105), used2(2 * n);

    for(int _ = 0; _ < n; _++)
    {
        if(_ < k2)
        {
            for(int i = 0; i < 2 * n; i++)
            {
                if(used2[i] == 0 && used[a[i]] == 0 && b[a[i]] >= 2)
                {
                    used[a[i]] = 1;
                    used2[i] = 1;
                    b[a[i]]--;
                    break;
                }
            }
        }
        else if(k1 > nk1)
        {
            for(int i = 0; i < 2 * n; i++)
            {
                if(used2[i] == 0 && used[a[i]] == 0)
                {
                    used2[i] = 1;
                    used[a[i]] = 1;
                    b[a[i]]--;
                    k1--;
                    nk1++;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < 2 * n; i++)
            {
                if(used2[i] == 0 && b[a[i]] >= 2)
                {
                    b[a[i]]--;
                    used2[i] = 1;
                    break;
                }
            }
        }
    }

    cout << (k2 + k1) * (k2 + nk1) << "\n";

    for(int i = 0; i < 2 * n; i++)
        cout << used2[i] + 1 << ' ';
}