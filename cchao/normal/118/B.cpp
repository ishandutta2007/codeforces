#include <bits/stdc++.h>
using namespace std;

void f(int a, int b) {
    while(a--) cout << ' ';
    for(int i = 0; i < b; ++i) cout << i << ' ';
    for(int i = b; i >= 0; --i) cout << i << (i==0?'\n':' ');
}

int main() {
    int n; cin >> n;
    for(int i = n*2, j= 0; i >= 0; i -= 2, ++j) f(i, j);
    for(int i = 2, j= n-1; i <= n*2; i += 2, --j) f(i, j);
    return 0;
}