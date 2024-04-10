#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
string s;
char a[2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    int x = 0;
    int L = n / 2 - 1;
    int R = n / 2;

    if(n % 2)
    {
        x = 1;
        a[n / 2] = s[0];

        L = n / 2 - 1;
        R = n / 2 + 1;
    }

    while(x < n)
    {
        a[L] = s[x];
        a[R] = s[x + 1];

        L--;
        R++;
        x += 2;
    }

    for(int i = 0; i < n; i++)
        cout << a[i];
}