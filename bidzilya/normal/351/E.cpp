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

const int max_n = 2e3;

int n;
int a[max_n];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    bool found = true;
    while (found) {
        found = false;
        for (int i = 0; i < n; ++i) {
            int i1 = 0, i2 = 0;
            for (int j = 0; j < n; ++j) {
                if (j < i && a[j] > a[i] ||
                    j > i && a[j] < a[i]) ++i1;
                if (j < i && a[j] > -a[i] ||
                    j > i && a[j] < -a[i]) ++i2;
            }
            if (i2 < i1) {
                a[i] *= -1;
                found = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j])
                ++ans;
    cout << ans << endl;
    return 0;
}