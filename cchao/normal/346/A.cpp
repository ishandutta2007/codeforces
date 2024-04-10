#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, g, m; scanf("%d", &n);
    for(int i = 0, t; i < n; ++i) {
        scanf("%d", &t);
        if(i) g = __gcd(g, t), m = max(m, t);
        else g = m = t;
    }
    puts( (m/g - n)&1 ? "Alice" : "Bob" );
    return 0;
}