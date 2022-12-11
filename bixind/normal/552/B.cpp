#include <iostream>

using namespace std;

int main()
{
    long long n, i, s, ans;
    cin >> n;
    if(n < 10) {cout << n; return 0;}
    s = 10;
    i = 1;
    ans=0;
    while (s <= n)
    {
        ans+=(s/10)*9*i;
        i++;
        s*=10;
    }
    s/=10;
    ans+=(n - s + 1) * i;
    cout << ans;
    return 0;
}