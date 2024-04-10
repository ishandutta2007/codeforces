#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;
char a[30];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    int L = 0, R = 26;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        for(int i = 0; i < M; i++)
            a[i] = 'a' - 1;

        int F = 1;

        for(int i = 0; i < n; i++)
        {
            int x = -1;

            for(int j = 0; j < M; j++)
                if(a[j] <= s[i] && (x == -1 || a[j] >= a[x]))
                    x = j;

            if(x == -1)
                F = 0;
            else a[x] = s[i];
        }

        if(F)
            R = M;
            else L = M;
    }

    cout << R << "\n";
    int M = R;

        for(int i = 0; i < M; i++)
            a[i] = 'a' - 1;

        for(int i = 0; i < n; i++)
        {
            int x = -1;

            for(int j = 0; j < M; j++)
                if(a[j] <= s[i] && (x == -1 || a[j] >= a[x]))
                    x = j;

            a[x] = s[i];
            cout << x + 1 << ' ';
        }

}