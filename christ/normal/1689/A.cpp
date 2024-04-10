#include<bits/stdc++.h>
using namespace std;
const int MN = 100+5;
char s[MN], t[MN];
void solve () {
    int n,m,k; scanf ("%d %d %d",&n,&m,&k);
    scanf ("%s\n%s",s+1,t+1);
    sort(s+1,s+1+n);
    sort(t+1,t+1+m);
    int i = 1, j = 1, lst = 0, cnt = 0;
    string ret;
    while (i <= n && j <= m) {
        if (cnt == k) {
            if (lst == 0) ret += t[j++], lst = 1;
            else ret += s[i++], lst = 0;
            cnt = 1;
            continue;
        }
        if (s[i] < t[j]) {
            ret += s[i++];
            if (lst == 0) ++cnt;
            else cnt = 1, lst = 0;
        } else {
            ret += t[j++];
            if (lst == 1) ++cnt;
            else cnt = 1, lst = 1;
        }
    }
    printf ("%s\n",ret.c_str());
}
int main () {
    int _t; scanf ("%d",&_t);
    while (_t--) solve();
    return 0;
}