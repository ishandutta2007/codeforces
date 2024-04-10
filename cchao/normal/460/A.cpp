#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; ; ++i) {
        if(n == 0) {ans = i - 1; break;}
        n--;
        if(i % m == 0) n++;
    }
    cout << ans << endl;
    return 0;
}