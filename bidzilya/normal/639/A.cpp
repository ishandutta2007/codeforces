#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TBox {
    void Init(int k) {
        K = k;
    }

    bool IsIn(int x) {
        for (int i = 0; i < (int) Values.size(); ++i) {
            if (Values[i].second == x) {
                return true;
            }
        }
        return false;
    }

    void Add(const pair<int, int>& x) {
        Values.push_back(x);
        sort(Values.begin(), Values.end(), greater<pair<int, int>>());
        if (Values.size() > K) {
            Values.resize(K);
        }
    }

    vector<pair<int, int>> Values;
    int K;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    TBox box;
    box.Init(k);

    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int id;
            cin >> id;
            --id;
            box.Add(make_pair(t[id], id));
        } else {
            int id;
            cin >> id;
            --id;
            if (box.IsIn(id)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    cout.flush();

    return 0;
}