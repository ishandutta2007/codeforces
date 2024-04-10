#include <bits/stdc++.h>

using namespace std;
typedef int var;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var a, b, c;
    var mina, minb, minc;
    var maxa, maxb, maxc;

    var n;
    cin>>n;
    cin>>mina>>maxa>>minb>>maxb>>minc>>maxc;

    n -= mina + minb + minc;

    cout<<(mina + min(maxa - mina, n))<<' ';
    n -= min(maxa - mina, n);
    cout<<(minb + min(maxb - minb, n))<<' ';
    n -= min(maxb - minb, n);
    cout<<(minc + min(maxc - minc, n))<<' ';
    n -= min(maxc - minc, n);

    return 0;
}