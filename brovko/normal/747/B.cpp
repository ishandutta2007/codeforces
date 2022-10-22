#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, b[128];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    if(n % 4)
    {
        cout << "===";
        return 0;
    }

    for(auto to:s)
    {
        b[to]++;

        if(to != '?' && b[to] > n / 4)
        {
            cout << "===";
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(s[i] != '?')
            cout << s[i];
        else
        {
            if(b['A'] < n / 4)
            {
                b['A']++;
                cout << 'A';
            }
            else if(b['C'] < n / 4)
            {
                b['C']++;
                cout << 'C';
            }
            else if(b['G'] < n / 4)
            {
                b['G']++;
                cout << 'G';
            }
            else if(b['T'] < n / 4)
            {
                b['T']++;
                cout << 'T';
            }
        }
    }
}