#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#ifdef ONLINE_JUDGE
#include <iostream>
#else
ifstream cin("input.txt");
ofstream cout("output.txt");
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main() {
    int n;
    cin >> n;
    int k = 0, m = 0;
    for (int i = 0; i < 2 * n; ++i) {
        string s;
        cin >> s;
        int j = 0;
        while (s[j] != '.') ++j;
        ++j;
        int x = (s[j] - '0') * 100 + (s[j + 1] - '0') * 10 + (s[j + 2] - '0');
        if (x != 0) {
            k += x;
            ++m;
        }
    }
    int ans;
    bool found = 0;
    for (int i1 = max(0, m - n); i1 <= min(m, n); ++i1)
        if (!found) {
            ans = abs(i1 * 1000 - k);
            found = 1;
        } else {
            ans = min(abs(i1 * 1000 - k), ans);
        }
    cout << ans / 1000 << ".";
    cout << (ans % 1000) / 100 << (ans % 100) / 10 << ans % 10 << endl;
    return 0;
}