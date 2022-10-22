#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a, b;
vector <char> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> a >> b;

    int x = 0;

    for(int i = 0; i < n; i++)
    {
        if(x == k)
        {
            x = 1;

            if(v[i - 1] == 'B')
            {
                v.push_back('G');
                a--;
            }
            else
            {
                v.push_back('B');
                b--;
            }

            if(a < 0 || b < 0)
            {
                cout << "NO";
                return 0;
            }
        }
        else
        {
            if(a > b)
            {
                a--;
                v.push_back('G');
            }
            else
            {
                b--;
                v.push_back('B');
            }

            if(i == 0 || v[i] != v[i - 1])
                x = 1;
            else x++;
        }
    }

    for(auto to:v)
        cout << to;
}