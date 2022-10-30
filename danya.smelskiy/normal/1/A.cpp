#include <iostream>

using namespace std;

int main() {
    long long n, m, a;
    __int128 nl, ml, al;
    cin >> n >> m >> a;
    nl = n;
    ml = m;
    al = a;
    __int128 resl = ((nl + al - 1ll) / al) * ((ml + al - 1ll) / al);
    long long res = (long long)resl;
    cout << res << '\n';
    return 0;
}