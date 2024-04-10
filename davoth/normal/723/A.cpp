#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y,z;
    cin >> x >> y >> z;
    cout << max(max(x,y),z)-min(min(x,y),z);
    return 0;
}