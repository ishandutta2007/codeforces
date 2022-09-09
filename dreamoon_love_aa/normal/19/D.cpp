#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<set>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB push_back
using namespace std;
const int INF = 2e9;
const int SIZE = 1 << 18;
int oper[SIZE][3];
int ma[SIZE * 2];
set<int> nodes[SIZE * 2];
void ins(int L, int R, int id, const pair<int, int> &p, int ty) {
    if(L == R) {
        if(ty == 1) {
            nodes[p.first].insert(p.second);
        } else {
            nodes[p.first].erase(p.second);
        }
        ma[id] = nodes[p.first].empty() ? -1 : *nodes[p.first].rbegin();
        return;
    }
    int m = (L + R) / 2;
    if(p.first <= m) ins(L, m, id * 2, p, ty);
    else ins(m + 1, R, id * 2 + 1, p, ty);
    ma[id] = max(ma[id * 2], ma[id * 2 + 1]);
}
int query(int L, int R, int id, const pair<int, int> &p) {
    if(ma[id] < p.second) return -1;
    if(R < p.first) return -1;
    if(L == R) return L;
    int m = (L + R) / 2;
    int ret = query(L, m, id * 2, p);
    if(ret != -1) return ret;
    return query(m + 1, R, id * 2 + 1, p);
}
void solve() {
    int n;
    scanf("%d", &n);
    vector<int> xs;
    for(int i = 0; i < n; i++) {
        ma[i] = -1;
        char s[12];
        scanf("%s%d%d", s, &oper[i][1], &oper[i][2]);
        xs.push_back(oper[i][1]);
        if(s[0] == 'a') oper[i][0] = 1;
        else if(s[0] == 'f') oper[i][0] = 2;
    }
    sort(xs.begin(), xs.end());
    for(int i = 0; i < n; i++) {
        int x = oper[i][1];
        int y = oper[i][2];
        x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        if(oper[i][0] == 1) ins(0, n - 1, 1, MP(x, y), 1);
        else if(oper[i][0] == 0) ins(0, n - 1, 1, MP(x, y), -1);
        else {
            int ans = query(0, n - 1, 1, MP(x + 1, y + 1));
            if(ans == -1) puts("-1");
            else printf("%d %d\n", xs[ans], *nodes[ans].upper_bound(y));
        }
    }
}
int main() {
    solve();
    return 0;
}