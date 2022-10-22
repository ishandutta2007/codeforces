#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main() {
    int n,p,q;
    cin >> n >> p >> q;
    p=min(p,q);
    if(n>p) cout << "NO";
    else cout << "YES";
    return 0;
}