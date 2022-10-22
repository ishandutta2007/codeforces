#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int p, x;
    cin >> p >> x;
    
    if(p == 1 && x == 1)
    {
        cout << 1;
        return 0;
    }

    int mz = 1;

    for(int i = 0; i < p - 1; i++)
        mz = mz * 10 % (10 * x - 1);

    for(int i = x; i < 10; i++)
    {
        int my = i * (mz - x) % (10 * x - 1);

        if(my == 0)
        {
            vector <int> v;

            for(int i = 0; i < p - 1; i++)
                v.pb(9);

            v.pb(i - 1);

            int j = 0;
            int y = x * i;

            while(y > 0)
            {
                v[j] = 9 - y % 10;

                if(j == 0)
                    v[j]++;

                j++;
                y /= 10;
            }

//            for(auto to:v)
//                cout << to;
//
//            return 0;

            int p = 0, f = 0, F = 1;

            for(int i = (int)v.size() - 1; i >= 0; i--)
            {
                if(i <= p - 3 && f == 0)
                {
                    F = 0;
                    break;
                }

                p = p * 10 + v[i];

                if(p >= 10 * x - 1)
                {
                    f = 1;
                    cout << p / (10 * x - 1);
                    p %= (10 * x - 1);
                }
                else
                {
                    if(f)
                        cout << 0;
                }
            }

            if(F)
            {
                cout << i;
                return 0;
            }

        }
    }

    cout << "Impossible";
}