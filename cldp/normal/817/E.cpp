#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 27;
const int MAXN = 4000010;
const int INF = 1000000007;
const double PI = acos(-1.0);

struct node {
    int L, R, sum;
};

int MM;
node X[MAXN];

void add(int a) {
    int p = 0;
    for (int i = MAXL; i >= 0; --i) {
        ++X[p].sum;
        if (a & (1 << i)) {
            if (X[p].R == 0) X[p].R = ++MM;
            p = X[p].R;
        } else {
            if (X[p].L == 0) X[p].L = ++MM;
            p = X[p].L;
        }
    }
    ++X[p].sum;
}

void del(int a) {
    int p = 0;
    for (int i = MAXL; i >= 0; --i) {
        --X[p].sum;
        if (a & (1 << i)) {
            p = X[p].R;
        } else {
            p = X[p].L;
        }
    }
    --X[p].sum;
}

int dfs(int p, int a, int &b, int &c) {
    int ans = 0;
    if (b & (1 << a)) {
        if (c & (1 << a)) {
            if (X[p].R != 0) ans += X[X[p].R].sum;
            if (X[p].L != 0) ans += dfs(X[p].L, a - 1, b, c);
        } else {
            if (X[p].R != 0) ans += dfs(X[p].R, a - 1, b, c);
        }
    } else {
        if (c & (1 << a)) {
   // cout << p << " " << a << " " << b << " " << c << " " << ans << " 1" << endl;
            if (X[p].L != 0) ans += X[X[p].L].sum;
            if (X[p].R != 0) ans += dfs(X[p].R, a - 1, b, c);
        } else {
            if (X[p].L != 0) ans += dfs(X[p].L, a - 1, b, c);
        }
    }
  //  cout << p << " " << a << " " << b << " " << c << " " << ans << endl;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    while (N--) {
        int a, b, c;
        cin >> a;
        if (a == 3) {
            cin >> b >> c;
            cout << dfs(0, MAXL, b, c) << endl;
            continue;
        } 
        cin >> b;
        if (a == 1) add(b); else del(b);
    }
  //  for (int i = 0; i <= MM; ++i) cout << X[i].L << " " << X[i].R << " " << X[i].sum << endl;
    return 0;
}