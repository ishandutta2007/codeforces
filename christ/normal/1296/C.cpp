#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
char s[MN];
void solve () {
    int n;
    scanf ("%d",&n);
    scanf ("%s",s);
    assert(strlen(s) == n);
    map<pii,int> lst;
    int hori = 0, vert = 0; lst[{0,0}] = -1;
    int ret = INT_MAX, l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L' || s[i] == 'R') hori += s[i]=='L'?-1:1;
        else vert += s[i]=='U'?1:-1;
        pii cur = {hori,vert};
        if (lst.count(cur) && i-lst[cur] < ret) {
            ret = i-lst[cur];
            l = lst[cur]+1;
            r = i;
        }
        lst[cur] = i;
    }
    if (ret > 1e9) printf ("-1\n");
    else printf ("%d %d\n",l+1,r+1);
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}