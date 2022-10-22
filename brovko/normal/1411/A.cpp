#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        string s;

        cin >> n >> s;

        int k = 0;

        while(k < n && s[n - 1 - k] == ')')
            k++;

        if(k > n - k)
            cout << "Yes\n";
        else cout << "No\n";
    }
}