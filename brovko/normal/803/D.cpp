#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s, t;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    getline(cin, t);
    getline(cin, s);

    int x = 0;

    for(auto to:s)
    {
        x++;
        if(to == '-' || to == ' ')
        {
            v.push_back(x);
            x = 0;
        }
    }

    v.push_back(x);
    int m = v.size();

    int L = 0;
    int R = 1e9;

    /*for(auto to:v)
        cout << to << ' ';
    cout << "\n";*/

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int y = 1;
        int z = 0;

        for(int i = 0; i < m; i++)
            {
                if(z + v[i] > M)
                {
                    z = v[i];
                    y++;
                }
                else z += v[i];

                if(z > M)
                    y = 1e9;
            }

        if(y <= k)
            R = M;
        else L = M;
    }

    cout << R;
}