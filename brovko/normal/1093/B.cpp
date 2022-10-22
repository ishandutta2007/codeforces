#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, t;
char c[1005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> s;
        n=s.size();
        for(int i=0;i<n;i++)
            c[i]=s[i];
        sort(c, c+n);
        if(c[0]==c[n-1])
            cout << -1;
        else for(int i=0;i<n;i++)
            cout << c[i];
        cout << "\n";
    }
}