#include <bits/stdc++.h>
using namespace std;

pair<int, int> ordered(int u, int v) {
    if (u > v) swap(u, v);
    return {u, v};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i: a) cin >> i;
    long long mx_cnt = count(a.begin(), a.end(), *max_element(a.begin(), a.end()));
    a.insert(a.end(), a.begin(), a.end());
    
    deque<int> qu;
    for (int i = 0; i < n; ++i) {
        while (qu.size() and a[qu.back()] < a[i]) qu.pop_back();
        qu.push_back(i);
    }
    
    long long eq_pairs = 0;
    set<pair<int, int>> pairs;
    
    auto true_pos = [&](int p) {
        if (p >= n) return p - n;
        return p;
    };
    
    for (int i = n; i < 2 * n; ++i) {
        while (qu.size() and qu.front() <= i - n) qu.pop_front();
        while (qu.size() and a[qu.back()] < a[i]) {
            pairs.insert(ordered(true_pos(qu.back()), i - n));
            // clog << i << ' ' << qu.back() << endl;
            qu.pop_back();
        }
        int l = 0, r = (int)qu.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[qu[mid]] == a[i]) r = mid;
            else l = mid + 1;
        }
        eq_pairs += qu.size() - l;
        // clog << eq_pairs << endl;
        if (l) {
            pairs.insert(ordered(true_pos(qu[l - 1]), i - n));
            // clog << i << ' ' << qu[l - 1] << endl;
        }
        qu.push_back(i);
    }
    
    
    cout << eq_pairs + (long long)pairs.size() - mx_cnt * (mx_cnt - 1) / 2;
    
    return 0;
}