#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 202, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
void solve () {
    int k,n,a,b;
    scanf ("%d %d %d %d",&k,&n,&a,&b); --k;
    if (k/b < n) return (void) printf ("-1\n");
    printf ("%d\n",min((n*b-k)/(b-a),n));
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}