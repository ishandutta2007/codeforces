#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    int a, b, m, r0;
    cin >> a >> b >> m >> r0;
    
    int cur = 1;
    vector<int> was(m);
    was[r0] = 1;
    while (true) {
        ++cur;
        r0 = (1LL*a*r0+b)%m;
        if (was[r0]) {
            cout << cur - was[r0] << endl;
            return 0;
        }
        was[r0] = cur;
    }
    
    return 0;
}