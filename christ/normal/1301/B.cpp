#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e5+2, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
char a[MN], b[MN], c[MN];
void solve () {
    int n;
    scanf ("%d",&n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf ("%d",&a[i]);
    }
    vector<int> ree;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1 && ((i&&a[i-1] == -1) || (i!=n-1&&a[i+1] == -1))) ree.push_back(a[i]);
    }
    sort(all(ree));
    int take;
    if (ree.size() > 1) take = (ree[0] + ree[ree.size()-1]) / 2;
    else if (ree.size() == 1) take = ree[0];
    else take = 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) a[i] = take;
        if (i) ret = max(ret,abs(a[i]-a[i-1]));
    }
    printf ("%d %d\n",ret,take);
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}