//  228

#include <bits/stdc++.h>
using namespace std;
int a, b;
char t;
int main() {
    cin >> a >> t >> b;
    cout << (double)((a % 12) * 30 + (b / 2.0)) << " " << b * 6;
    return 0;
}