#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;
const int MOD1 = 998244353;
const int MOD2 = 1e9 + 7;
const int MOD4 = 1e9 + rand();

int n, k;
string a[100005];

int f(string x)
{
    int ans = 0;

    for(auto to:x)
        if(to != '-')
    {
        ans = 10 * ans + to - '0';
    }

    if(x[0] == '-')
        ans = -ans;

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n + 1; i++)
        cin >> a[i];
        
    if(k == 0)
    {
        if(a[0] == "0")
            cout << "Yes";
        else if(a[0] != "?")
            cout << "No";
        else
        {
            int k = 0;
            
            for(int i = 0; i <= n; i++)
                if(a[i] != "?")
                k++;
            
            if(k % 2)
                cout << "Yes";
            else cout << "No";
        }
        
        return 0;
    }

    int F = 0;

    for(int i = 0; i < n + 1; i++)
        if(a[i] == "?")
            F = 1;

    if(F == 0)
    {
        int x1 = 0;
        int x2 = 0;
        int x3 = 0;
        int x4 = 0;

        for(int i = n; i >= 0; i--)
        {
            x1 = (x1 * k + f(a[i])) % MOD1;
            x2 = (x2 * k + f(a[i])) % MOD2;
            x3 = x3 * k + f(a[i]);
            x4 = (x4 * k + f(a[i])) % MOD4;
        }

        if(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0)
            cout << "Yes";
        else cout << "No";
    }
    else
    {
        if(n % 2 == 0)
            cout << "No";
        else cout << "Yes";
    }
}