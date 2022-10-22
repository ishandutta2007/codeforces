#include <bits/stdc++.h>
#define int long long


using namespace std;

int x;
int gcd(int a, int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x;
    int p=sqrt(x);
    for(int i=p;i>=1;i--)
        if(x%i==0 && gcd(i, x/i)==1)
    {
        cout << i << ' ' << x/i;
        return 0;
    }
}