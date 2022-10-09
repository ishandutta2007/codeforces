#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (k % 2 == 1)
        ans = (k + 1) / 2;
    else
        ans = (n + 2 - k) / 2;
    cout << ans;
}