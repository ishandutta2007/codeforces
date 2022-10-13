#include <bits/stdc++.h>

using namespace std;
typedef int var;


var X[2005], Y[2005];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    var n;
    cin>>n;

    for(var i=1; i<=n; i++) {
        cin>>X[i]>>Y[i];
    }

    var cnt = 0;

    for(var i=1; i<=n; i++) {
        for(var j=i+1; j<=n; j++) {
            for(var k=j+1; k<=n; k++) {
                cnt += (X[k] - X[j]) * (Y[i] - Y[j]) != (Y[k] - Y[j]) * (X[i] - X[j]);
            }
        }
    }

    cout<<cnt;


    return 0;
}