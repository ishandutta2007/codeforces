//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 1000000000

int n, k1, k2;
int w, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n >> k1 >> k2 >> w >> b;
    if((w<=(min(k1,k2)+(abs(k1-k2)/2)))&&(b<=(n+(abs(k1-k2)/2)-max(k1,k2)))) cout << "YES" << endl;
    else cout << "NO" << endl;
}
    return 0;
}