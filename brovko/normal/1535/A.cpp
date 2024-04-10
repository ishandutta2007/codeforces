#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, s1, s2, s3, s4;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s1 >> s2 >> s3 >> s4;

        if(max(s1, s2) > min(s3, s4) && max(s3, s4) > min(s1, s2))
            cout << "YES\n";
        else cout << "NO\n";
    }
}