#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    if(k>n+1)
    {
        cout << "No";
        return 0;
    }

    for(int i=1;i<=min(k, 100000ll);i++)
    {
        if(n%i!=i-1)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}