#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
int ans[N];

map<tuple<int, int, int>, int> M;

int query(int a, int b, int c) {
    int x[3] = {a, b, c};
    sort(x, x + 3);
    auto t = make_tuple(x[0], x[1], x[2]);
    if (M.count(t)) return M[t];
    cout << "? " << x[0] << " " << x[1] << " " << x[2] << endl;
    int v; cin >> v;
    M[t] = v;
    return v;
}

int get5(int a, int b, int c, int d, int e) {
    int x[5] = {a, b, c, d, e};
    vector<long long> vec;
    vec.push_back(query(a, b, c));
    vec.push_back(query(a, b, d));
    vec.push_back(query(a, b, e));
    vec.push_back(query(a, c, d));
    vec.push_back(query(a, c, e));
    vec.push_back(query(a, d, e));
    vec.push_back(query(b, c, d));
    vec.push_back(query(b, c, e));
    vec.push_back(query(b, d, e));
    vec.push_back(query(c, d, e));
    sort(vec.begin(), vec.end());
    long long t = 0;
    for (long long _ : vec) t += _;
    t -= (vec[0] + vec[9] + vec[1] * 3 + vec[8] * 3);
    t /= 2;
    long long bd = vec[3];
    if (bd == t) bd = vec[6];
    long long C = (vec[0] + vec[9] - t) / 2;
    long long A = vec[0] - C, E = vec[9] - C;
    long long D = vec[1] - A, B = vec[8] - E;
    long long y[5] = {A, B, C, D, E}, z[5];
    int id[5] = {0, 1, 2, 3, 4};
    do {
        for (int i = 0; i < 5; i++) {
            z[id[i]] = x[i];
        }
        if (query(z[0], z[1], z[2]) != vec[0]) continue;
        if (query(z[0], z[1], z[3]) != vec[1]) continue;
        if (query(z[0], z[1], z[4]) != t) continue;
        if (query(z[0], z[2], z[3]) != vec[1]) continue;
        if (query(z[0], z[2], z[4]) != t) continue;
        if (query(z[0], z[3], z[4]) != t) continue;
        if (query(z[1], z[2], z[3]) != bd) continue;
        if (query(z[1], z[2], z[4]) != vec[8]) continue;
        if (query(z[1], z[3], z[4]) != vec[8]) continue;
        if (query(z[2], z[3], z[4]) != vec[9]) continue;
        for (int i = 0; i < 5; i++) ans[z[i]] = y[i];
        break;
    } while (next_permutation(id, id + 5));
}

int main() {
    memset(ans, -1, sizeof ans);
    int n; cin >> n;
    vector<pair<int, int>> values;
    for (int i = 3; i <= n; i++) {
        int v = query(1, 2, i);
        values.emplace_back(v, i);
    }
    sort(values.begin(), values.end());
    int id[3];
    for (int i : {0, 1, 2}) id[i] = values[i].second;
    get5(1, 2, id[0], id[1], id[2]);
    if (n == 5) {
        cout << "!";
        for (int i = 1; i <= 5; i++) {
            cout << " " << ans[i];
        }
        cout << endl;
        return 0;
    }
    int Mid = -1, Mval = 2e9 + 10;
    int _id[] = {1, 2, id[0], id[1], id[2]};
    for (int i = 0; i < 5; i++) {
        if (Mval > ans[_id[i]]) {
            Mval = ans[_id[i]];
            Mid = _id[i];
        }
    }
    vector<int> ids;
    for (int i = 1; i <= n; i++) {
        if (i == Mid) continue;
        ids.push_back(i);
    }
    values.clear();
    for (int i = 2; i < ids.size(); i++) {
        values.emplace_back(query(ids[0], ids[1], ids[i]), ids[i]);
    }
    sort(values.begin(), values.end());
    int __id[] = {ids[0], ids[1], values[0].second, values[1].second, values[2].second};
    memcpy(_id, __id, sizeof _id);
    get5(_id[0], _id[1], _id[2], _id[3], _id[4]);
    int NMid = -1;
    Mval = 2e9+10;
    for (int i = 0; i < 5; i++) {
        if (Mval > ans[_id[i]]) {
            Mval = ans[_id[i]];
            NMid = _id[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] >= 0) continue;
        int ret = query(Mid, NMid, i);
        ans[i] = ret - ans[Mid];
    }
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << ans[i];
    }
    cout << endl;
}