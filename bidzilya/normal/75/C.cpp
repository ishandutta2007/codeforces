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

int main() {
    ios_base::sync_with_stdio(false); 
    int a, b;
    cin >> a >> b;
    vector<int> d;
    for (int i = 1; i <= sqrt(a); ++i)
        if (a % i == 0) {
            d.push_back(i);
            if (i * i != a)
                d.push_back(a / i);
        }
    vector<int> d2;
    for (int i = 0; i < d.size(); ++i)
        if (b % d[i] == 0)
            d2.push_back(d[i]);
    sort(d2.begin(), d2.end());
    int q;
    for (cin >> q; q; --q) {
        int l, r;
        cin >> l >> r;
        int ans = -1;
        int bl = 0, br = d2.size() - 1;
        while (bl <= br) {
            int bm = (bl + br) >> 1;
            if (d2[bm] < l) 
                bl = bm + 1;
            else if (d2[bm] > r)
                br = bm - 1;
            else {
                ans = d2[bm];
                bl = bm + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}