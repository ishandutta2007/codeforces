#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    int max = 0;
    int prev = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        if (i != 0) {
            max = std::max(max, prev - val);
        }
        prev = val;
    }
    printf("%d", std::max(0, max - c));

}