#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;

    for(int i = 0; i < 64; i++)
    {
        char x;
        cin >> x;

        if(x == 'Q')
            ans += 9;

        if(x == 'R')
            ans += 5;

        if(x == 'B' || x == 'N')
            ans += 3;

        if(x == 'P')
            ans++;

        if(x == 'q')
            ans -= 9;

        if(x == 'r')
            ans -= 5;

        if(x == 'b' || x == 'n')
            ans -= 3;

        if(x == 'p')
            ans--;
    }

    if(ans > 0)
        cout << "White";
    else if(ans == 0)
        cout << "Draw";
    else cout << "Black";
}