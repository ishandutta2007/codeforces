#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        int b=(100-a);
        int g=gcd(a,b);
        cout << (a+b)/g << "\n";
    }
    return 0;
}