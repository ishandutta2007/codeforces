#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;


template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const T& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}


struct node_t {
    LL min_v = 1LL << 60;
    int min_p = (1 << 18) - 1;
    LL flag = 0;
} rt[2 << 18];

int query() {
    assert(rt[1].min_v == 0);
    return rt[1].min_p;
}

void update(int b, int e, LL v, int n = 1, int l = 0, int r = 1 << 18) {
    if(r <= b or e <= l) {
        return;
    }
    if(b <= l and r <= e) {
        rt[n].min_v += v;
        rt[n].flag += v;
        if(l + 1 == r) {
            rt[n].min_p = l;
        }
        return;
    }
    if(rt[n].flag) {
        rt[2 * n].min_v += rt[n].flag;
        rt[2 * n].flag += rt[n].flag;
        rt[2 * n + 1].min_v += rt[n].flag;
        rt[2 * n + 1].flag += rt[n].flag;
        rt[n].flag = 0;
    }
    update(b, e, v, 2 * n, l, (l + r) / 2);
    update(b, e, v, 2 * n + 1, (l + r) / 2, r);
    if(rt[2 * n].min_v < rt[2 * n + 1].min_v) {
        rt[n].min_v = rt[2 * n].min_v;
        rt[n].min_p = rt[2 * n].min_p;
    } else {
        rt[n].min_v = rt[2 * n + 1].min_v;
        rt[n].min_p = rt[2 * n + 1].min_p;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    for(int n = 0; n < N; ++n) {
        LL s;
        cin >> s;
        update(n, n + 1, s - (1LL << 60));
    }
    vector<int> ans(N, 0);
    for(int n = 1; n <= N; ++n) {
        int p = query();
        ans[p] = n;
        update(p, p + 1, 1LL << 60);
        update(p + 1, N, -n);
    }
    
    for(int n = 0; n < N; ++n) {
        cout << ans[n] << " ";
    }
    cout << "\n";
    
    
    return 0;
}