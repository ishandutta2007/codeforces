#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

int prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return i;
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int p=prime(n*(n+1)/2);
    if(p==0)
    {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";
    cout << "1 " << p << "\n";
    cout << n-1 << ' ';
    for(int i=1;i<=n;i++)
    {
        if(i!=p)
            cout << i << ' ';
    }
}