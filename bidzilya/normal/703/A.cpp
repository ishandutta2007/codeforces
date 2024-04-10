#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

int main() {
    int n;
    scanf("%d", &n);
    int wins[2];
    wins[0] = wins[1] = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) {
            ++wins[0];
        } else if (b > a) {
            ++wins[1];
        }
    }

    if (wins[0] > wins[1]) {
        printf("Mishka\n");
    } else if (wins[1] > wins[0]) {
        printf("Chris\n");
    } else {
        printf("Friendship is magic!^^\n");
    }

    return 0;
}