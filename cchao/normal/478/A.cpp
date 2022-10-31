#include <bits/stdc++.h>
using namespace std;

int main() {
    int s = 0;
    for(int i = 0, t; i < 5; ++i) {
        cin >> t;
        s += t;
    }
    if(s % 5 || s == 0) puts("-1");
    else cout << s / 5 << endl;
    return 0;
}