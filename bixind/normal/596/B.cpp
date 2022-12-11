#include <iostream>


using namespace std;

int main()
{
    long long i, n, pr = 0;
    long long ans = 0, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (pr < x) ans += x - pr;
        else
            ans += pr - x;
        pr = x;
    }
    cout << ans;
    return 0;
}