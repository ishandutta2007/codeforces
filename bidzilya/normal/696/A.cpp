#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

#include <cassert>
using namespace std;

long long GetFromMap(const unordered_map<long long, long long>& sum, long long pos) {
    auto itr = sum.find(pos);
    if (itr != sum.end()) {
        return itr->second;
    } else {
        return 0;
    }
}

vector<long long> GetVerts(long long u) {
    vector<long long> result;
    while (u >= 1) {
        result.push_back(u);
        u >>= 1;
    }
    reverse(result.begin(), result.end());
    return result;
}

long long GetLca(long long v, long long u) {
    vector<long long> vs = GetVerts(v);
    vector<long long> us = GetVerts(u);

    for (int i = 1; i < (int) min(vs.size(), us.size()); ++i) {
        if (vs[i] != us[i]) {
            return vs[i - 1];
        }
    }

    if (vs.size() < us.size()) {
        return vs.back();
    } else {
        return us.back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    unordered_map<long long, long long> sum;
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            long long v, u;
            cin >> v >> u;
            long long w;
            cin >> w;

            long long g = GetLca(v, u);

            while (v != g) {
                sum[v] += w;
                v >>= 1;
            }

            while (u != g) {
                sum[u] += w;
                u >>= 1;
            }
        } else {
            long long v, u;
            cin >> v >> u;

            long long g = GetLca(v, u);

            long long result = 0;

            while (v != g) {
                result += GetFromMap(sum, v);
                v >>= 1;
            }

            while (u != g) {
                result += GetFromMap(sum, u);
                u >>= 1;
            }

            cout << result << endl;
        }
    }


    return 0;
}