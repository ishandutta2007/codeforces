#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
using namespace std;
const double PI = acos(-1);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long sum = a[0];
    long long res = 0;
    for(int i = 1; i < n; i++)
    {
        res += a[i];
    }
    if(res > sum)
    {
        cout << 0 << "\n";
    }
    else cout <<  sum - res + 1 << "\n";
    return 0;
}