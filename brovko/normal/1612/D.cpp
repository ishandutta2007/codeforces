#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, a, b, x;

bool f(int a, int b, int x)
{
    if(a == 0)
        return 0;
    
    if(x > a && x > b)
        return 0;

    if(a == x || b == x)
        return 1;

    if(b % a == x % a)
        return 1;
        
    return f(b % a, a, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> x;

        if(f(a, b, x))
            cout << "YES\n";
        else cout << "NO\n";
    }
}