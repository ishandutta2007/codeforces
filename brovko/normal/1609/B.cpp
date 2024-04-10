#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define li long long

using namespace std;

int n, q;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> s;

    int k = 0;

    for(int i = 0; i < (int)s.size() - 2; i++)
        if(s.substr(i, 3) == "abc")
            k++;

    while(q--)
    {
        int pos;
        char c;

        cin >> pos >> c;

        pos--;

        for(int i = pos - 2; i <= pos; i++)
            if(i >= 0 && i < (int)s.size() - 2 && s.substr(i, 3) == "abc")
                k--;

        s[pos] = c;

        for(int i = pos - 2; i <= pos; i++)
            if(i >= 0 && i < (int)s.size() - 2 && s.substr(i, 3) == "abc")
                k++;

        cout << k << "\n";
    }
}