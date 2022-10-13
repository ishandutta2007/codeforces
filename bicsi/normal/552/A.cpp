#include <bits/stdc++.h>

using namespace std;
typedef int var;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    int64_t total = 0;
    int a, b, c, d;

    cin>>n;
    while(n--) {
        cin>>a>>b>>c>>d;
        total += (c-a+1)*(d-b+1);
    }

    cout<<total;

    return 0;
}