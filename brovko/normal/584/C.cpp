#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, t;
string s1, s2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t >> s1 >> s2;
    t = n - t;

    int c = 0;

    for(int i = 0; i < n; i++)
        if(s1[i] != s2[i])
            c++;

    int X = -1, Y = -1, Z = -1;

    for(int y = 0; 2 * y <= c; y++)
    {
        int x = c - 2 * y;
        int z = t - y;

        if(x + y > c || x < 0 || y < 0 || z < 0 || z > n - c);
            else
            {
                X = x;
                Y = y;
                Z = z;
            }
    }

    if(X == -1)
    {
        cout << -1;
        return 0;
    }

//    cout << X << ' ' << Y << ' ' << Z << endl;

    for(int i = 0; i < n; i++)
    {
        if(s1[i] != s2[i])
        {
            if(X > 0)
            {
                X--;

                char ans = 'a';

                while(ans == s1[i] || ans == s2[i])
                    ans++;

                cout << ans;
            }
            else if(Y > 0)
            {
                Y--;
                cout << s2[i];
            }
            else cout << s1[i];
        }
        else
        {
            if(Z > 0)
            {
                Z--;
                cout << s1[i];
            }
            else
            {
                char ans = 'a';

                while(ans == s1[i])
                    ans++;

                cout << ans;
            }
        }
    }
}