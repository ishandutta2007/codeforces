#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
int ask(int a , int b)
{
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 2; i < n + 1; i++)
    {
        ll x = (n / i - 1) * i;
        ans += x;
    }
    cout << ans * 4 << "\n";
    return 0;
}