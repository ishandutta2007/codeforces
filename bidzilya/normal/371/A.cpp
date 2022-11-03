#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

const int max_n = 111;


int n, k;
int a[max_n];


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int c1 = 0, c2 = 0;
        for (int j = i; j < n; j += k)
            if (a[j] == 1) {
                ++c1;
            } else {
                ++c2;
            }
        ans += min(c1, c2);
    }
    cout << ans << endl;
    return 0;
}