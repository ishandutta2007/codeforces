#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int q[1005];

int query(int l, int r)
{
    cout << "? 2 " << l + 1 << ' ' << r + 1 << endl;

    int ans;
    cin >> ans;

    if(l == 0)
        q[r] = ans;

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> New;
    string s;

    q[0] = 1;

    for(int i = 0; i < n; i++)
    {
        if(i == 0 || query(0, i) != q[i - 1])
        {
            cout << "? 1 " << i + 1 << endl;

            char c;
            cin >> c;
            s += c;

            New.pb(i);
        }
        else
        {
            int L = 0, R = New.size();

            while(R - L > 1)
            {
                int M = (L + R) / 2;

                if(query(New[M], i) == New.size() - M)
                    L = M;
                else R = M;
            }

            s += s[New[L]];

            New[L] = i;
            sort(New.begin(), New.end());
        }
    }

    cout << "! " << s << endl;
}