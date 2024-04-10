#include <bits/stdc++.h>
#define li long long
#define pb push_back

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if(abs(a - b) > 1 || a + b + 2 > n)
        {
            cout << "-1\n";
            continue;
        }

        if(a >= b)
        {
            vector <int> v;

            int x = 1, y = n;

            for(int i = 0; i < a; i++)
            {
                v.pb(x++);
                v.pb(y--);
            }

            if(a == b)
            {
                while(v.size() < n)
                    v.pb(x++);
            }
            else
            {
                while(v.size() < n)
                    v.pb(y--);
            }

            if(v.size() > n)
                cout << "-1\n";
            else
            {
                for(auto x:v)
                    cout << x << ' ';

                cout << "\n";
            }
        }
        else
        {
            vector <int> v;

            int x = -n, y = -1;

            for(int i = 0; i < b; i++)
            {
                v.pb(x++);
                v.pb(y--);
            }

            if(a == b)
            {
                while(v.size() < n)
                    v.pb(x++);
            }
            else
            {
                while(v.size() < n)
                    v.pb(y--);
            }

            if(v.size() > n)
                cout << "-1\n";
            else
            {
                for(auto x:v)
                    cout << -x << ' ';

                cout << "\n";
            }
        }
    }
}