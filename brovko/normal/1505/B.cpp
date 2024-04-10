#include <bits/stdc++.h>
#define int long long

using namespace std;

int f(int x)
{
    if(x == 0)
        return 0;

    return x % 10 + f(x / 10);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while(f(n) != n)
        n = f(n);
    
    cout << n;
}