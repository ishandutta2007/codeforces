#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <random>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long
int cnt[N];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0, sum = 0, iter = 1;
    for(int i = 0; i < N; i++)
    {
        int height = N - i;
        ans += cnt[height];
        if(ans >= n)
        {
            break;
        }
        sum += ans;
        if(sum > k)
        {
            iter++;
            sum = ans;
        }
    }
    cout << (sum ? iter : iter - 1) << "\n";
}