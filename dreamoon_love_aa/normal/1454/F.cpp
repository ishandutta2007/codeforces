#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void answer_YES(int x, int y, int z){
    puts("YES");
    printf("%d %d %d\n", x, y, z);
}
const int SIZE = 2e5 + 5;
int a[SIZE];
void solve() {
    map<int,vector<int>> pos;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        pos[-x].push_back(i);
    }
    int l = n + 1, r = 0;
    int greater_v_cnt = 0;
    for(const auto &[x, vi]: pos) {
        int v = -x;
        if(l > n) {
            if(vi.size() > 2) {
                answer_YES(vi[1] - 1, 1, n - vi[1]);
                return;
            }
        } else {
            int v_in_range_cnt = 0;
            for(int p: vi) {
                if(p >= l && p <= r) {
                    v_in_range_cnt++;
                }
            }
            if(v_in_range_cnt > 0 && r - l + 1 == v_in_range_cnt + greater_v_cnt && vi[0] < l && vi.back() > r) {
                answer_YES(l - 1, r - l + 1, n - r);
                return;
            }
            if(r - l + 1 == greater_v_cnt && vi[0] < l && vi.back() > r + 1 && a[r + 1] == v) {
                answer_YES(l - 1, r - l + 2, n - r - 1);
                return;
            }
            if(r - l + 1 == greater_v_cnt && vi[0] < l - 1 && vi.back() > r && a[l - 1] == v) {
                answer_YES(l - 2, r - l + 2, n - r);
                return;
            }
        }
        for(int p: vi) {
            l = min(l, p);
            r = max(r, p);
        }
        greater_v_cnt += SZ(vi);
    }
    puts("NO");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}