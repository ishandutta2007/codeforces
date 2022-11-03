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

const int max_n = 4e3 + 100;

int n;
int a[max_n];
int d[max_n][max_n], f[max_n][max_n];
int cls[max_n];
int classes = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        bool fnd = 0;
        for (int j = 0; j < i; ++j)
            if (a[i] == a[j]) {
                fnd = 1;
                cls[i] = cls[j];
                break;
            }
        if (!fnd) {
            ++classes;
            cls[i] = classes;
        }
    }
    for (int i = 0; i < n; ++i) {
        int c = cls[i];
        for (int j = 1; j <= classes; ++j) {
            if (f[j][c]) {
                f[c][j] = 1;
                d[c][j] = max(d[c][j], d[j][c] + 1);
            }
            if (f[j][0]) {
                d[c][j] = max(d[c][j], 2);
                f[c][j] = 1;
            }
        }
        d[c][0] = f[c][0] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= classes; ++i)
        for (int j = 0; j <= classes; ++j)
            ans = max(ans, d[i][j]);
    cout << ans << endl;
        
                
    return 0;
}