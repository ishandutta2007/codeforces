#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a = 1, b = n * n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n / 2; ++j) printf("%d %d ", a++, b--);
        puts("");
    }
    return 0;
}