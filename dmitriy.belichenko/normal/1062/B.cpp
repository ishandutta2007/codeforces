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
map<int , int> cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int k = n;
    for(int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cnt[i]++;
            n /= i;
        }
    }
    if(n > 1)
    {
        cnt[n]++;
    }
    n = k;
    int norm = 1;
    int ans = 0;
    int mx = 0;
    for(auto v : cnt)
    {
        norm *= v.first;
        mx = max(mx , v.second);
    }
    int x = 0;
    while (mx & (mx - 1))
    {
     //   cout <<  (mx & (mx - 1)) << " ";
        mx++;
        x++;
    }
    for(auto v : cnt)
    {
        if(v.second != mx)
        {
            ans = 1;
        }
    }
    while(mx)
    {
        ans++;
        mx /= 2;
    }
    cout << norm << " " << max(0 , ans - 1) << "\n";
    return 0;
}