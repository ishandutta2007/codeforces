#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, k, b[128];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> s;

        int f = 0, x = 0, y = 0, km = 0;

        for(int i = 'a'; i <= 'z'; i++)
            b[i] = 0;

        for(int i = 0; i < n; i++)
        {
            if(b[s[i]] % k == 0)
                km += k;

            b[s[i]]++;

            km--;
        }

        if(km == 0)
        {
            f = 1;
            x = n;
        }

        for(int i = n - 1; i >= 0; i--)
        {
            b[s[i]]--;
            km++;

            if(b[s[i]] % k == 0)
                km -= k;

            for(int j = s[i] + 1; j <= 'z'; j++)
            {
                if(b[j] % k == 0)
                    km += k;

                b[j]++;
                km--;

                if(km < n - i && f == 0)
                {
                    f = 1;
                    x = i;
                    y = j;
                }

                b[j]--;
                km++;

                if(b[j] % k == 0)
                    km -= k;
            }
        }

        if(n % k)
            cout << "-1\n";
        else
        {
            for(int j = 'a'; j <= 'z'; j++)
                b[j] = 0;

            km = 0;

            for(int i = 0; i < x; i++)
            {
                cout << s[i];

                if(b[s[i]] % k == 0)
                    km += k;

                b[s[i]]++;
                km--;
            }

            if(x < n)
            {
                cout << char(y);

                if(b[y] % k == 0)
                    km += k;

                b[y]++;
                km--;
            }

            while(n - 1 - x > km)
            {
                km++;
                cout << 'a';
            }

            for(int j = 'a'; j <= 'z'; j++)
                for(int z = b[j]; z % k; z++)
                    cout << char(j);

            cout << "\n";
        }
    }
}