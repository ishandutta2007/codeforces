#include <cstdio>
#include <cstring>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_m = 1e3 + 10;

int n, m, h;
int a[max_m];
int sum = 0;

int main() {
    cin >> n >> m >> h;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    --sum;
    --a[h];
    --n;
    if (sum < n) {
        cout << -1.0 << endl;
    } else {
        long double ans = 1.0;
        for (int i = 0; i < n; ++i)
            ans = ans * (sum - a[h] - i) / (sum - i);
        cout << 1 - ans << endl;
    }
    
    return 0;
}