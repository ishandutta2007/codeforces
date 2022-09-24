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
const ll MOD = 1e9 + 7;
ll p[N] , a[N];
ll q , n;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for(int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = 1001;
    n = n + 2;
    int ans = 0;
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = i + 2 ; j < n ; j++)
        {
            if(a[j] - a[i] == j - i)
            {
                ans = max(ans , j - i - 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}