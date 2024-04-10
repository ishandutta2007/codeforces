#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 1e5 + 100;

int a[max_n];
int sum[max_n];
int n;
string s;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sum[0] = 0;
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i - 1];
    cin >> s;
    int ans = 0;
    int cans = 0;
    for (int i = n - 1; i >= 0; --i)
        if (s[i] == '1') {
            ans = max(ans, cans + sum[i]);
            cans += a[i];
        }
    ans = max(ans, cans);
    cout << ans << endl;
    return 0;
}