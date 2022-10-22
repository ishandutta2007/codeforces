#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
char s[MN];
void solve () {
    int n,k;
    scanf ("%d %d",&n,&k);
    scanf ("%s",s);
    assert((int)strlen(s) == n);
    int fi = -1, ed = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && fi == -1) fi = i;
        if (s[i] == '1') ed = i;
    }
    if (fi == -1) {
        printf ("0\n");
        return;
    }
    auto get = [&] () {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i > 0) ret++;
                if (i + 1 < n) ret += 10;
            }
        }
        return ret;
    };
    int ret = get();
    //move first 1 to start
    if (fi <= k) {
        swap(s[fi],s[0]);
        ret = min(ret,get());
        swap(s[fi],s[0]);
    }
    if (n - 1 - ed <= k) {
        swap(s[n-1],s[ed]);
        ret = min(ret,get());
        swap(s[n-1],s[ed]);
    }
    if (fi != ed && fi + n - 1 - ed <= k) {
        swap(s[n-1],s[ed]);
        swap(s[0],s[fi]);
        ret = min(ret,get());
    }
    printf ("%d\n",ret);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}