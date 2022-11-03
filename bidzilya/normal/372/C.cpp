#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int max_n = 3e5 + 100;
const int max_m = 444;

int a[max_n][2];
int n, m, d;
ll ans;
int ax[max_m];
int t[max_m];

struct my_queue {
    deque<int> q;
  
    void push(int x) {
        while (!q.empty() && q.back() > x) 
            q.pop_back();
        q.push_back(x);
    }
    
    int get() {
        return q.front();
    }
    
    void pop(int x) {
        if (!q.empty() && q.front() == x) 
            q.pop_front();
    }
};

int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> ax[i] >> temp >> t[i];
        --ax[i];
        ans += temp;
    }
    int id = 0;
    for (int i = 0; i < m; ++i) {
        int nid = (id + 1) % 2;
        int dt = t[i];
        if (i > 0) dt -= t[i - 1];
        int dx = min(1LL * n, 1LL * d * dt);
        my_queue q;
        int l = 0, r = min(n - 1, dx);
        for (int j = 0; j <= r; ++j)
            q.push(a[j][id]);
        for (int j = 0; j < n; ++j) {
            int nl = max(0, j - dx);
            int nr = min(n - 1, j + dx);
            for (int k = l; k < nl; ++k)
                q.pop(a[k][id]);
            for (int k = r + 1; k <= nr; ++k)
                q.push(a[k][id]);
            l = nl;
            r = nr;
            a[j][nid] = q.get() + abs(ax[i] - j);
        }
        id = nid;
    }
    int mn = a[0][id];
    for (int i = 1; i < n; ++i)
        mn = min(mn, a[i][id]);
    ans -= mn;
    cout << ans << endl;
    return 0;
}