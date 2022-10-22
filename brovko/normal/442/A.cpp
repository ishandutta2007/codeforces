#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, mask;

int rec(int d, vector <int> v, vector <int> u)
{

    int F = 1;

    for(int i = 0; i < 25; i++)
        for(int j = 0; j < i; j++)
            if(mask & (1 << i) && mask & (1 << j) && v[i / 5] == v[j / 5] && u[i % 5] == u[j % 5])
                F = 0;

//    if(F && d == 1)
//    {
//        cout << d << endl;
//        for(auto x:v)
//            cout << x << ' ';
//
//        cout << endl;
//
//        for(auto x:u)
//            cout << x << ' ';
//
//        cout << endl;
//
//        exit(0);
//    }

    if(F)
        return 0;

    int ans = 1e9;

    int fv = 1, fu = 1;

    for(int i = 0; i < 5; i++)
    {
        if(v[i] == 0 && fv)
        {
            v[i] = d + 1;
            ans = min(ans, 1 + rec(d + 1, v, u));
            v[i] = 0;
        }
        else fv = 0;

        if(u[i] == 0 && fu)
        {
            u[i] = d + 1;
            ans = min(ans, 1 + rec(d + 1, v, u));
            u[i] = 0;
        }
        else fu = 0;
    }

//    cout << d << endl;
//    for(auto x:v)
//        cout << x << ' ';
//
//    cout << endl;
//
//    for(auto x:u)
//        cout << x << ' ';
//
//    cout << endl;
//
//    cout << ans << endl << endl;

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int x = s[1] - '1';

        if(s[0] == 'R')
            x += 5;

        if(s[0] == 'G')
            x += 10;

        if(s[0] == 'B')
            x += 15;

        if(s[0] == 'Y')
            x += 20;

        mask |= (1 << x);
    }

//    cout << mask << endl;

    cout << rec(0, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0});
}