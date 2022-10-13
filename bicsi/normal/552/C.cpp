#include <bits/stdc++.h>

using namespace std;
typedef int64_t var;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    var n, w;
    cin>>w>>n;

    for(var i=0; i<100; i++) {
        var r = n % w;
        n /= w;

        if(r <= 1)
            continue;
        if(r == w-1) {
            n ++;
            continue;
        }

        cout<<"NO";
        return 0;
    }
    cout<<"YES";


    return 0;
}