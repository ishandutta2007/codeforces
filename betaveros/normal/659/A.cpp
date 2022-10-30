#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int main() {
    cin >> n >> a >> b;
    int k = (a + b) % n;
    if (k < 0) k += n;
    cout << (k == 0 ? n : k) << "\n";
}