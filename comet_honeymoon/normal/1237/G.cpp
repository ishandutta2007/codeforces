#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll a[100005], avg;

vector<int> lis[100005];
int fa[20][100005];

int ans = -1, ansid = -1, anspos = -1;
vector<int> anscut;

void solve(int id, const vector<int> pos, bool flg) {
    for (int i = 0; i < pos.size(); i++) lis[pos[i] % k].push_back(i);

    // bit lifting init
    for (int i = 0; i < pos.size(); i++) {
        fa[0][i] = -1;
        vector<int> &nlis = lis[(pos[i] + 1) % k];
        if (!nlis.size()) continue;
        int faa = lower_bound(nlis.begin(), nlis.end(), i + 1) - nlis.begin();
        if (faa != nlis.size()) fa[0][i] = nlis[faa];
        // if (pos.size() >= 2) printf("u = %d : %d\n", pos[i], fa[0][i]);
    }
    if (flg) {
        int u = anspos;
        while (u != -1) {
            anscut.push_back(pos[u]);
            u = fa[0][u];
        }
        return;
    }
    for (int d = 0; d + 1 < 20; d++)
    for (int i = 0; i < pos.size(); i++) {
        fa[d + 1][i] = -1;
        if (fa[d][i] == -1) continue;
        fa[d + 1][i] = fa[d][fa[d][i]];
    }

    // bit lifting
    for (int i = 0; i < pos.size(); i++) if (lis[pos[i] % k][0] == i) {
        int qaq = 0, u = i;
        for (int d = 19; d >= 0; d--)
            if (fa[d][u] != -1) u = fa[d][u], qaq += 1 << d;
        if (qaq > ans)
            ans = qaq, ansid = id, anspos = i;
    }

    for (int i = 0; i < pos.size(); i++) lis[pos[i] % k].clear();
}

vector<int> pos[100005];
int idx; map<ll, int> hsh;

vector<vector<int> > ANS;
void calc(int l, int r, int x, int y) {
    int len = (r - l + n) % n + 1;
    if (len == 1) return;
    if (len <= k + 1) {
        vector<int> qaq; qaq.push_back(l);
        bool flg = 0;
        for (int i = l, j = 0; j <= k; i = (i + 1) % n, j++) {
            int w = 0;
            if (i == l) w = x;
            else if (i == r) w = y, flg = 1;
            else if (flg) w = a[i];
            a[i] = w;
            qaq.push_back(w);
        }
        ANS.push_back(qaq);
        return;
    }
    ll sum = 0;
    for (int i = l, j = 0; j <= k; i = (i + 1) % n, j++)
        sum += a[i];
    if (sum >= x) {
        vector<int> qaq; qaq.push_back(l);
        for (int i = l, j = 0; j <= k; i = (i + 1) % n, j++) {
            int w = 0;
            if (i == l) w = x;
            else if (i == (l + k) % n) w = sum - x;
            a[i] = w;
            qaq.push_back(w);
        }
        ANS.push_back(qaq);
        calc((l + k) % n, r, 0, y);
    }
    else {
        calc((l + k) % n, r, a[(l + k) % n] + x - sum, y);
        vector<int> qaq; qaq.push_back(l);
        for (int i = l, j = 0; j <= k; i = (i + 1) % n, j++) {
            int w = 0;
            if (i == l) w = x;
            a[i] = w;
            qaq.push_back(w);
        }
        ANS.push_back(qaq);
    }
}

int main() {
    scanf("%d%d", &n, &k); k--;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), avg += a[i];
    avg /= n;
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1] - avg;
    
    // discrete
    for (int i = 1; i <= n; i++) {
        if (!hsh.count(a[i]))
            hsh[a[i]] = ++idx;
        pos[hsh[a[i]]].push_back(i);
    }

    // main
    for (int i = 1; i <= idx; i++) solve(i, pos[i], 0);
    // printf("qwq %d\n", ansid);
    solve(ansid, pos[ansid], 1);
    // printf("cut = "); for (int u : anscut) printf("%d ", u); printf("\n");

    for (int i = n; i; i--) a[i] -= a[i - 1]; 
    for (int i = 0; i < n; i++) a[i] = a[i + 1];
    for (int i = 0; i < anscut.size(); i++) {
        calc(anscut[i], (anscut[(i + 1) % anscut.size()] - 1 + n) % n, 0, 0);
    }

    printf("%d\n", ANS.size());
    for (vector<int> qaq : ANS) {
        printf("%d ", qaq[0]);
        for (int i = 1; i < qaq.size(); i++) printf("%d ", qaq[i] + avg);
        printf("\n");
    }
}