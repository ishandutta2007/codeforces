#include<bits/stdc++.h>
using namespace std;

const int maxn = 500005;

int n, M;
int a[maxn];
vector<int> zps;
int L[maxn], R[maxn];

vector<int> Qry[maxn];
int tag[maxn];

void solve() {
    zps.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) zps.push_back(i);
    }
    M = zps.size() / 2;

    for (int i = 1; i <= n; i++) L[i] = -1, R[i] = M;
    for (int i = 1, j = -1; i <= n; i++) {
        if (a[i]) L[a[i]] = max(L[a[i]], j); else j++;
        if (j == M) break;
    }
    for (int i = n, j = M; i; i--) {
        if (a[i]) R[a[i]] = min(R[a[i]], j); else j--;
        if (j == -1) break;
    }

    int ans = 0;
    for (int i = 0; i <= M; i++)
        Qry[i].clear(), tag[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (L[i] >= R[i]) { ans++; continue; }
        if (L[i] >= 0 || R[i] < M)
            Qry[L[i] + 1].push_back(R[i]);
    }
    priority_queue<int, vector<int>, greater<int> > Q;
    for (int i = -1; i < M; i++) 
    for (int R : Qry[i + 1]) {
        Q.push(R);
        if (Q.size() > i + 1) tag[Q.top()]++, Q.pop();
    }
    ans += Q.size();
    for (int i = M, cnt = 0; i >= 0; i--, cnt++)
        ans += min(tag[i], cnt),
        cnt -= min(tag[i], cnt);
    printf("%d\n", min(ans, M));
}

int main() {
    int T; scanf("%d", &T);
    while (T--) solve();
}