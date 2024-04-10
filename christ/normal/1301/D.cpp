#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e5+2, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int k;
vector<pair<int,char>> out;
void go (char dir, int cnt) {
    if (cnt == 0) return;
    if (cnt > k) cnt = k;
    out.emplace_back(cnt,dir);
    k -= cnt;
    if (!k) {
        printf ("%d\n",out.size());
        for (auto &au : out) printf ("%d %c\n",au.first,au.second);
        exit(0);
    }
}
int main() {
    int n,m;
    scanf ("%d %d %d",&n,&m,&k);
    if (k > 4*n*m-2*n-2*m) return !printf ("NO\n");
    printf ("YES\n");
    go('D',n-1);
    go('R',m-1);
    go('U',n-1);
    for (int i = 0; i < m-2; i++) {
        go('L',1);
        go('D',n-1);
        go('U',n-1);
    }
    go('L',1);
    go('R',m-1);
    for (int i = 0; i < n-2; i++) {
        go('D',1);
        go('L',m-1);
        go('R',m-1);
    }
    go('D',1);
    go('L',m-1);
    go('U',n-1);
    assert(0);
    return 0;
}