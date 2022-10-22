#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int MN = 202;
int cnt[MN];
pii p[MN];
bool done[MN];
int main() {
    int n,K,a,b;
    scanf ("%d %d",&n,&K);
    for (int i = 1; i <= n; i++) {
        scanf ("%d %d",&p[i].first,&p[i].second);
        for (int j = p[i].first; j <= p[i].second; j++) cnt[j]++;
    }
    vector<int> inds;
    while (1) {
        bool ok = 1;
        for (int i = 1; i <= 200; i++) if (cnt[i] > K) {
            ok = 0;
            int mx = 0, best = -1;
            for (int j = 1; j <= n; j++) if (!done[j] && p[j].first <= i && i <= p[j].second) {
                int ret = 0;
                for (int k = p[j].first; k <= p[j].second; k++) if (cnt[k] > K) ++ret;
                if (ret > mx) {
                    mx = ret;
                    best = j;
                }
            }
            for (int j = p[best].first; j <= p[best].second; j++) --cnt[j];
            inds.push_back(best);
            done[best] = 1;
            break;
        }
        if (ok) break;
    }
    sort(inds.begin(),inds.end());
    printf ("%d\n",inds.size());
    for (int i : inds) printf ("%d ",i);
    putchar(10);
    return 0;
}