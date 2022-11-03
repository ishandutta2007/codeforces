#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <cassert>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(101, 0);
    for (int i = 0; i < n; ++i) {
        int ca;
        cin >> ca;
        ++a[ca];
    }

    vector<int> order;
    for (int rem = 9; rem >= 0; --rem) {
        for (int i = 0; i < 100; ++i) {
            if (i % 10 == rem) {
                order.push_back(i);
            }
        }
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (auto x: order) {
            int need = 10 - (x % 10);
            
            int max_c = min(a[x], k / need);

            k -= (need * max_c);
            a[x + need] += max_c;
            a[x] -= max_c;

            if (max_c != 0) {
                changed = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
        ans += a[i] * (i / 10);
    }

    cout << ans << endl;


    return 0;
}