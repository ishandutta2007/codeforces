#include<bits/stdc++.h>

using namespace std;
const int N = 3005;
int head[N], ver[N << 1], Next[N << 1], tot = 1;
int n, m, deg[N], cur, sum, th[N], tv[N << 1];
bool v[N << 1];
vector<int> ans;
set<int> del;
stack<int> stk;

inline void add(int x, int y) {
    ver[++tot] = y;
    Next[tot] = head[x];
    head[x] = tot;
}

inline void solve(int x) {
    while (!stk.empty())stk.pop();
    stk.push(x), ans.clear();
    memcpy(th, head, sizeof(int) * (n + 1));
    memcpy(tv, v, sizeof(bool) * (tot + 1));
    while (!stk.empty()) {
        int y = stk.top(), i = head[y];
        while (i && v[i])i = Next[i];
        if (i)stk.push(ver[i]), v[i] = v[i ^ 1] = true, head[y] = Next[i];
        else stk.pop(), ans.push_back(y);
    }
    if (ans.size() == sum / 2 + 1) {
        ans.push_back(-1);
        for (int i:del)ans.push_back(ver[i]), ans.push_back(x);
        printf("%d\n", ans.size());
        for (int y:ans)printf("%d ", y);
        exit(0);
    }
    memcpy(head, th, sizeof(int) * (n + 1));
    memcpy(v, tv, sizeof(bool) * (tot + 1));
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
        deg[x]++, deg[y]++, sum += 2;
    }
    for (int i = 1; i <= n; i++)if (deg[i] & 1)cur++;
    for (int x = 1; x <= n; x++) {
        for (int i = head[x]; i; i = Next[i])
            if (deg[ver[i]] & 1) {
                deg[ver[i]]--, deg[x]--;
                cur--, sum -= 2;
                v[i] = v[i ^ 1] = true;
                del.insert(i);
            }
        if (del.size() & 1)deg[x] & 1 ? cur++ : cur--;
        if (deg[x] & 1 && cur == 2)solve(x);
        if (!cur)
            for (int i = head[x]; i; i = Next[i]) {
                if (v[i]) {
                    v[i] = v[i ^ 1] = false;
                    deg[x]++, deg[ver[i]]++, sum += 2;
                    del.erase(i);
                } else {
                    v[i] = v[i ^ 1] = true;
                    deg[x]--, deg[ver[i]]--, sum -= 2;
                    del.insert(i);
                }
                solve(x);
                if (v[i]) {
                    v[i] = v[i ^ 1] = false;
                    deg[x]++, deg[ver[i]]++, sum += 2;
                    del.erase(i);
                } else {
                    v[i] = v[i ^ 1] = true;
                    deg[ver[i ^ 1]]--, deg[ver[i]]--, sum -= 2;
                    del.insert(i);
                }
            }
        if (del.size() & 1)deg[x] & 1 ? cur-- : cur++;
        for (int i:del) {
            deg[x]++, deg[ver[i]]++;
            cur++, sum += 2;
            v[i] = v[i ^ 1] = false;
        }
        del.clear();
    }
    return puts("0"), 0;
}