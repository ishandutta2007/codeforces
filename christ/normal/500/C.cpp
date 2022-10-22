#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 15e4+3, MOD = 1e9+7;
int getans (vector<int> a, vector<int> &w, vector<int> &m) {
    int ret = 0;
    for (int i = 1; i < m.size(); i++) {
        int cur = m[i], sum = 0, pos = -1;
        for (int i = 1; i < a.size(); i++) if (a[i] == cur) {
            ret += sum;
            pos = i;
            break;
        } else sum += w[a[i]];
        assert(~pos);
        a.erase(a.begin()+pos);
        a.insert(a.begin()+1,cur);
    }
    return ret;
}
int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    vector<int> w(n+1);
    for (int i = 1;i  <= n; i++ )scanf ("%d",&w[i]);
    vector<int> go(m+1);
    for (int i = 1; i <= m; i++) scanf ("%d",&go[i]);
    vector<int> ree = {0}; vector<bool> done(n+1);
    for (int i = 1; i <= m; i++) if (!done[go[i]]) ree.push_back(go[i]), done[go[i]] = 1;
    printf ("%d\n",getans(ree,w,go));
    return 0;
}