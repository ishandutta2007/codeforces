#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

using li = long long;

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
        int a[2][2];

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                cin >> a[i][j];

        if(a[0][0] * a[1][1] * a[0][1] * a[1][0])
            cout << "2\n";
        else if(a[0][0] + a[1][1] + a[0][1] + a[1][0])
            cout << "1\n";
        else cout << "0\n";
    }
}