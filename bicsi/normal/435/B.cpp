#include <bits/stdc++.h>

using namespace std;

int main() {
    string a; cin >> a;
    int k; cin >> k;

    while (a.size()) {
        pair<char, int> best{0, -1};
        for (int i = 0; i < (int)a.size(); ++i) {
            if (i <= k) {
                best = max(best, make_pair(a[i], -i));    
            }
        }
        k += best.second;
        cout << best.first;
        a.erase(a.begin() - best.second);
    }

    return 0;
}