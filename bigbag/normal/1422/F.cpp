#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 200222, mod = 1000000007;
const int max_v = 36000111;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    int res = 1 % mod;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        b /= 2;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

struct node {
    int l, r, prod;
};

node t[max_v];
int curv;

int build(int l, int r) {
    int res = curv++;
    t[res].prod = 1;
    if (l == r) {
        return res;
    }
    int mid = (l + r) / 2;
    t[res].l = build(l, mid);
    t[res].r = build(mid + 1, r);
    return res;
}

int update(int v, int l, int r, int pos, int x) {
    int res = curv++;
    t[res] = t[v];
    if (l == r) {
        t[res].prod = mul(t[res].prod, x);
        return res;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        t[res].l = update(t[res].l, l, mid, pos, x);
    } else {
        t[res].r = update(t[res].r, mid + 1, r, pos, x);
    }
    t[res].prod = mul(t[t[res].l].prod, t[t[res].r].prod);
    return res;
}

int get_prod(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v].prod;
    }
    int mid = (tl + tr) / 2;
    if (r <= mid) {
        return get_prod(t[v].l, tl, mid, l, r);
    } else if (l > mid) {
        return get_prod(t[v].r, mid + 1, tr, l, r);
    }
    return mul(get_prod(t[v].l, tl, mid, l, mid),
               get_prod(t[v].r, mid + 1, tr, mid + 1, r));
}

int n, q, a[max_n], last[max_n], rev[max_n], roots[max_n];
bool not_is_prime[max_n];
vector<int> v;

void get_all_p() {
    for (int i = 1; i < max_n; ++i) {
        rev[i] = inv(i);
    }
    for (int i = 2; i < max_n; ++i) {
        if (!not_is_prime[i]) {
            long long x = i;
            while (x < max_n) {
                v.push_back(x);
                x *= i;
            }
            for (int j = 2 * i; j < max_n; j += i) {
                not_is_prime[j] = 1;
            }
        }
    }
}

int root;

void proc(int i, int x, int cnt) {
    int cur = 1;
    for (int j = 0; j < cnt; ++j) {
        cur *= x;
        if (last[cur] != -1) {
            //cout << last[cur] << " " << "/= " << x << endl;
            root = update(root, 0, n - 1, last[cur], rev[x]);
        }
        last[cur] = i;
        //cout << i << " " << "*= " << x << endl;
    }
    if (cnt) {
        root = update(root, 0, n - 1, i, cur);
    }
}

void build_all() {
    memset(last, -1, sizeof(last));
    root = build(0, n - 1);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int p = 2; p * p <= x; ++p) {
            int cnt = 0;
            while (x % p == 0) {
                ++cnt;
                x /= p;
            }
            proc(i, p, cnt);
        }
        if (x > 1) {
            proc(i, x, 1);
        }
        roots[i] = root;
        //cout << "#" << get_prod(root, 0, n - 1, 0, i) << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_p();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    build_all();
    scanf("%d", &q);
    int last = 0;
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int l = (last + x) % n;
        int r = (last + y) % n;
        if (l > r) {
            swap(l, r);
        }
        int ans = get_prod(roots[r], 0, n - 1, l, r);
        //cout << l << " " << r << ": " << roots[r] << ": ";
        printf("%d\n", ans);
        last = ans;
    }
    return 0;
}