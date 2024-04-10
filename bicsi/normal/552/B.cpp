#include <bits/stdc++.h>

using namespace std;
typedef int64_t var;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    var n;
    cin>>n;

    var total = 0;
    for(var t=1; t<=n+1; t*=10) {
        total += max(0LL, n-t+1);
    }

    cout<<total;

    return 0;
}