#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, pref[2000005];
string s, t;

int f(char c)
{
    if(c == 'N')
        return 'S';

    if(c == 'S')
        return 'N';

    if(c == 'W')
        return 'E';

    if(c == 'E')
        return 'W';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> t;
    n--;

    string q = "";

    for(int i = 0; i < n; i++)
        q += f(s[n - 1 - i]);

    q = q + "#" + t;

    swap(s, q);

    int k = 0;

//    cout << s << endl;

    for(int i = 1; i <= 2 * n; i++)
    {
        while(k > 0 && s[k] != s[i])
            k = pref[k - 1];

        if(s[k] == s[i])
            k++;

        pref[i] = k;
    }

    if(pref[2 * n] > 0)
        cout << "NO";
    else cout << "YES";
}