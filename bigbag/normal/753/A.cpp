#include <bits/stdc++.h>

using namespace std;

const int max_n = 111111, inf = 1011111111;

int n, m, ans, a[max_n], t[max_n];
vector<int> v[max_n];
multiset<int> q;

void update(int i, int x) {
    for (; i < max_n; i = (i | (i + 1))) {
        t[i] += x;
    }
}

int get(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += t[r];
    }
    return res;
}

void add(int l, int r, int x) {
    update(l, x);
    update(r + 1, -x);
}

struct point {
    int x, y;
    void write() {
        cout << x << " " << y << endl;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; n >= i; ++i) {
        v.push_back(i);
        n -= i;
    }
    v.back() += n;
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    return 0;
}