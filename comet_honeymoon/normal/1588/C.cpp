#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int maxn = 600005;
const int inf = 0x3f3f3f3f;

int n;
int a[maxn]; ll s[maxn];
ll STmin[20][maxn];

bool isvalid(int l, int r) {
    int rr;
    int k;
    k = 0;
    rr = r - ((r & 1) != (l & 1));
    while (l + (1 << (k + 2)) - 2 <= r) k++;
    if (STmin[k][l] < s[l] || STmin[k][rr - (1 << (k + 1)) + 2] < s[l]) return 0;
    k = 0;
    rr = r - ((r & 1) == (l & 1));
    while (l + 1 + ((1 << (k + 2)) - 2) <= r) k++;
    if (STmin[k][l + 1] + s[l] < 0 || STmin[k][rr - (1 << (k + 1)) + 2] + s[l] < 0) return 0;
    return 1;
}

map<ll, int> hsh; int idx;
int getid(ll x) {
    if (!hsh.count(x)) hsh[x] = idx++;
    return hsh[x];
}
vector<int> lis[2][maxn]; int he[2][maxn];

signed main() {
    int T; scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]),
            s[i] = a[i] - s[i - 1],
            STmin[0][i] = s[i];
        for (int k = 1; k < 20; k++)
        for (int i = 0; i <= n; i++) if (i + (1 << (k + 1)) - 2 <= n)
            // STmax[k][i] = max(STmax[k - 1][i], STmax[k - 1][i + (1 << k)]),
            STmin[k][i] = min(STmin[k - 1][i], STmin[k - 1][i + (1 << k)]);
        
        ll ans = 0;
        idx = 0;
        for (int i = 0; i <= n; i++) {
            int id, k;
            k = i & 1; id = getid(s[i]);
            for (int j = he[k][id]; j < lis[k][id].size(); j++)
                if (!isvalid(lis[k][id][j], i)) he[k][id]++;
                else break;
            ans += lis[k][id].size() - he[k][id];
            lis[k][id].push_back(i);

            k ^= 1; id = getid(-s[i]);
            for (int j = he[k][id]; j < lis[k][id].size(); j++)
                if (!isvalid(lis[k][id][j], i)) he[k][id]++;
                else break;
            ans += lis[k][id].size() - he[k][id];
            // if (i == 14) printf("check %d %d %d\n", lis[k][id].size() - he[k][id], lis[k][id][lis[k][id].size() - 2], lis[k][id][lis[k][id].size() - 1]);
        }
        printf("%lld\n", ans);

        hsh.clear();
        for (int i = 0; i < idx; i++) lis[0][i].clear(), he[0][i] = 0, lis[1][i].clear(), he[1][i] = 0;
        idx = 0;
    }
}