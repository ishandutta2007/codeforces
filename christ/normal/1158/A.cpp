#include <bits/stdc++.h>
using namespace std;
int main () {
    int n,m;
    scanf ("%d %d",&n,&m);
    int mxB = 0; long long ret = 0;
    vector<int> b(n);
    for (auto &au : b) {
        scanf ("%d",&au);
        ret += m * 1LL * au;
    }
    sort(b.begin(),b.end());
    bool ok = 0; mxB = b.back();
    for (int i = 1; i <= m; i++) {
        int g; scanf ("%d",&g);
        if (g < mxB) return !printf ("-1\n");
        if (g == mxB) ok = 1;
        ret += g - mxB;
    }
    if (!ok) {
        if ((int)b.size() == 1) return !printf ("-1\n");
        ret += b.back() - b.end()[-2];
    }
    printf ("%lld\n",ret);
    return 0;
}