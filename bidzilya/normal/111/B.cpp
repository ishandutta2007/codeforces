#include <cstdio>
#include <cstring>
#include <cmath>

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

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_n = 1e5 + 10;

int n;
int max_id[max_n];

int main() {
    ios_base::sync_with_stdio(false); 
    for (int i = 0; i < max_n; ++i)
        max_id[i] = -1;
    cin >> n;
    for (int id = 0; id < n; ++id) {
        int x, y, ans = 0;
        cin >> x >> y;
        for (int i = 1; i <= sqrt(x); ++i)
            if (x % i == 0) {
                if (max_id[i] < id - y) ++ans;
                max_id[i] = id;
                if (i * i != x) {
                    if (max_id[x / i] < id - y) ++ans;
                    max_id[x / i] = id;
                }
            }
        cout << ans << endl;
    }
    return 0;
}