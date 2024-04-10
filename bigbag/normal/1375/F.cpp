#include <bits/stdc++.h>

using namespace std;

const long long inf = 100000000000LL; // 10^11
//const long long inf = 100LL; // 10^11

pair<long long, int> a[3];

void proc() {
    sort(a, a + 3);
    a[1].first -= a[0].first;
    a[2].first -= a[0].first;
    a[0].first = 0;
}

const bool debug = 0;

mt19937 gen;
int LAST = -1;

int gen_move(long long x) {
    if (!debug) {
        int id;
        cin >> id;
        return id;
    }
    vector<int> v;
    for (int i = 0; i < 3; ++i) {
        a[i].first += x;
        bool ok = LAST != a[i].second;
        for (int j = 0; j < 3; ++j) {
            for (int k = j + 1; k < 3; ++k) {
                if (a[j].first == a[k].first) {
                    ok = 0;
                }
            }
        }
        a[i].first -= x;
        if (ok) {
            v.push_back(a[i].second);
        }
    }
    if (v.empty()) {
        return 0;
    }
    int res = v[gen() % v.size()];
    LAST = res;
    cout << "id = " << res + 1 << endl;
    return res + 1;
}

void make_move(long long x) {
    cout << x << endl;
    int id = gen_move(x);
    if (id == -1) {
        exit(228);
    }
    if (!id) {
        exit(0);
    }
    --id;
    for (int i = 0; i < 3; ++i) {
        if (a[i].second == id) {
            a[i].first += x;
        }
    }
    proc();
    if (debug) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a[j].second == i) {
                    cout << a[j].first << " ";
                }
            }
        }
        cout << endl;
    }
}

bool is_prog() {
    return a[1].first - a[0].first == a[2].first - a[1].first;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    proc();
    cout << "First" << endl;
    while (true) {
        if (a[1].first % 2 == a[2].first % 2) {
            break;
        }
        make_move(1);
    }
    if (a[0].first % 2 == a[1].first % 2) {
        make_move(inf);
    } else {
        make_move(inf / 10);
        if (a[1].first % 2 != a[2].first % 2) {
            make_move(inf - 1);
            assert(a[1].first % 2 == a[2].first % 2);
        }
    }
    const long long A = a[1].first;
    make_move((a[1].first + a[2].first) / 2);
    if (!is_prog()) {
        make_move(3 * A);
        assert(is_prog());
    }
    long long d = a[1].first - a[0].first;
    make_move(d);
    make_move(3 * d);
    make_move(5 * d);
    assert(is_prog());
    d = a[1].first - a[0].first;
    make_move(d);
    assert(false);
    return 0;
}