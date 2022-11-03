#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    bool good = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            scanf(" %c", &c);
            if (c == 'C' || c == 'M' || c == 'Y') {
                good = false;
            }
        }
    }

    printf("%s\n", (good ? "#Black&White" : "#Color"));

    return 0;
}