#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if(a == b) cout << a*10 << ' ' << b*10+1 << endl;
    else if(a+1 == b) cout << a*10+9 << ' ' << b*10 << endl;
    else if(a == 9 && b == 1) cout << 99 << ' ' << 100 << endl;
    else cout << -1 << endl;
}