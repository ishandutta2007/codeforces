#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int t, n, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;
        if(n%3==0)
            cout << a;
        else if(n%3==1)
            cout << b;
        else cout << (a^b);
        cout << "\n";
    }
}