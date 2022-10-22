#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if(n < 0)
    {
        n = -n;
        n = n / 100 * 10 + min(n % 10, n / 10 % 10);
        cout << -n;
    }
    else
    {
        cout << n;
    }
}