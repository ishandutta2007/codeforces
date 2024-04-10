#include <bits/stdc++.h>
using namespace std;

int main() {
    bitset<1000000010> b; int t;
    int n = 0;
    while(cin >> t)
        if(!b.test(t)) {
            n++;
            b.set(t);
        }
    cout << 4 - b.count() << endl;
    return 0;
}