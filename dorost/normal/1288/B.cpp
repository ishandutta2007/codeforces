#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << 1ll * a * (int)(log2(b + 1) / log2(10)) << endl;
    }
}