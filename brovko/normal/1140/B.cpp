#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int t, n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        int L=0;
        int R=n-1;
        while(L<n && s[L]=='<')
            L++;
        while(R>=0 && s[R]=='>')
            R--;
        cout << min(L, n-1-R) << "\n";
    }
}