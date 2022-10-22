#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int q, l, s;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x;
            cin >> x;
            v.push_back(x);
            if(l == 0)
                s = v[0];
        }
        else
        {
            int Max = v[(int)v.size() - 1];
            while(l < (int)v.size() - 1 && (ld)(s + Max) / (l + 2) > (ld)(s + Max + v[l + 1]) / (l + 3))
                {
                    l++;
                    s += v[l];
                }

            cout << setprecision(20) << Max - (ld)(s + Max) / (l + 2) << "\n";
        }
    }
}