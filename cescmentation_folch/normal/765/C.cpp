#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, a, b;
    cin >> k >> a >> b;
    int wa =  int(a/k);
    int wb = int(b/k);
    int res = wa + wb;
    if (wb == 0 and a%k > 0) res = 0;
    if (wa == 0 and b%k > 0) res = 0;
    if (res == 0) cout << -1 << endl;
    else cout << res << endl;
}