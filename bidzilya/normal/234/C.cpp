#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#ifdef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int max_n = 3e5;

int n;
int a[max_n];
int dp1[max_n], dp2[max_n];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dp1[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp1[i] = dp1[i - 1];
        if (a[i] >= 0)
            ++dp1[i];
    }
    dp2[n + 1] = 0;
    for (int i = n; i >= 1; --i) {
        dp2[i] = dp2[i + 1];
        if (a[i] <= 0)
            ++dp2[i];
    }
    int ans = dp1[1] + dp2[2];
    for (int i = 2; i < n; ++i)
        ans = min(ans, dp1[i] + dp2[i + 1]);
    cout << ans << endl;
        
    return 0;
}