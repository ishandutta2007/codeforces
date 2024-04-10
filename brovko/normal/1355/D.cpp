#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    if(s<2*n)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        cout << "YES\n";
        for(int i=0;i<n-1;i++)
            cout << 1 << ' ';
        cout << s-n+1 << "\n";
        cout << n;
    }
}