#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    set<pair<int, int> > S;
    S.insert(make_pair(N, 1));
    S.insert(make_pair(0, 0));
    int ans = N;
    for (int i = 0; i < K; ++i) {
        int l, r, k;
        cin >> l >> r >> k;

        auto iter = S.lower_bound(make_pair(l, 0));
        if (r > iter->first) {
            if (iter->second == 1 && k == 1) ans -= iter->first - l + 1;
            if (iter->second == 0 && k == 2) ans += iter->first - l + 1;
        } else {
            if (iter->second == 1 && k == 1) ans -= r - l + 1;
            if (iter->second == 0 && k == 2) ans += r - l + 1;
        }

        auto it2 = iter;
        --it2;
        int prevf = it2->first, currf = iter->first, currs = iter->second;
        S.erase(iter);
        if (prevf != l - 1) S.insert(make_pair(l - 1, currs));

        if (r <= currf) {
            if (k == 1) S.insert(make_pair(r, 0)); else S.insert(make_pair(r, 1));
            if (currf != r) S.insert(make_pair(currf, currs));
            cout << ans << endl;
            continue;
        } 

        l = currf + 1;
        while (true) {
            iter = S.lower_bound(make_pair(l, 0));
            if (r > iter->first) {
                if (iter->second == 1 && k == 1) ans -= iter->first - l + 1;
                if (iter->second == 0 && k == 2) ans += iter->first - l + 1;
            } else {
                if (iter->second == 1 && k == 1) ans -= r - l + 1;
                if (iter->second == 0 && k == 2) ans += r - l + 1;
            }
            currf = iter->first, currs = iter->second;
            S.erase(iter);
            if (r <= currf) {
                if (k == 1) S.insert(make_pair(r, 0)); else S.insert(make_pair(r, 1));
                if (currf != r) S.insert(make_pair(currf, currs));
                break;
            }
            l = currf + 1;
        }
        cout << ans << endl;
    }

    return 0;
}