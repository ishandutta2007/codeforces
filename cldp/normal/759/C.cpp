#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2000010;
const int INF = 1000000009;
const double PI = acos(-1.0);

int x[MAXN];
int sum[MAXN];
int maxh[MAXN];

void insert(int val, int p, int l, int r, int t) {
    if (l == r) {
        if (val > 0) {
            x[t] = val;
            sum[t] = 1;
            maxh[t] = 1;
        } else {
            x[t] = -1;
            sum[t] = -1;
            maxh[t] = -1;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) 
        insert(val, p, l, mid, t * 2);
    else
        insert(val, p, mid + 1, r, t * 2 + 1);

    sum[t] = sum[t + t] + sum[t + t + 1];
    maxh[t] = max(maxh[t + t + 1], maxh[t + t] + sum[t + t + 1]);
  //  cout << " ??? " << maxh[t + t + 1] << endl;
 //   cout << l << " " << r << " " << t << " " << maxh[t] << endl;
}

int query(int l, int r, int t, int off) {
 //   cout << "Q : " << l << " " << r << " " << maxh[t] << " " << off << endl;
    if (maxh[t] <= off) return -1;
    if (l == r) return x[t];
    int mid = (l + r) >> 1;
    if (maxh[t + t + 1] > off) return query(mid + 1, r, t + t + 1, off);
    return query(l, mid, t + t, off - sum[t + t + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, cnt = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int P, T, X;
        cin >> P >> T;
        if (T == 1) {
            cin >> X;
            insert(X, P, 1, N, 1);
        } else {
            insert(-1, P, 1, N, 1);
        }
        cout << query(1, N, 1, 0) << endl;
    }
    return 0;
}