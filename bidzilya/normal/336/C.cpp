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

const int max_n = 1e5 + 100;

int n;
int a[max_n];

int bit(int mask, int i) {
    return ((mask >> i) & 1);
}

void show(int x) {
    for (int i = 0; i < 31; ++i)
        cout << bit(x, i);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int v = 30; v >= 0; --v) {
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (bit(a[i], v)) {
                ans.push_back(a[i]);
            }
        if (!ans.size()) continue;
        int r = ans[0];
        for (int i = 1; i < ans.size(); ++i)
            r &= ans[i];
        if (!(r & ((1 << v) - 1))) {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); ++i)
                cout << ans[i] << " ";
            cout << endl;
            return 0;
        }
    }
    cout << n;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}