#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
  
typedef long long ll;

const int max_n = 5e3;

int n;
int a[max_n];

ll solve(int l, int r, int mn)
{
    if (l > r) return 0;
    int cur_mn = a[l];
    for (int i = l + 1; i <= r; ++i)
        cur_mn = min(cur_mn, a[i]);
    ll ans1 = r - l + 1;
    vector<int> pos;
    pos.push_back(l - 1);
    ll ans2 = cur_mn - mn;
    for (int i = l; i <= r; ++i)
        if (a[i] == cur_mn)
            pos.push_back(i);
    pos.push_back(r + 1);
    for (int i = 1; i < (int) pos.size(); ++i)
        ans2 += solve(pos[i - 1] + 1, pos[i] - 1, cur_mn);
    return min(ans1, ans2);
}

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
        
    cout << solve(0, n - 1, 0) << endl;
    

    return 0;
}