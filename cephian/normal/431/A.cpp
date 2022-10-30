#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int val[4];
    scanf("%d %d %d %d", &val[0], &val[1], &val[2], &val[3]);
    char str[100005];
    scanf("%s", str);
    int tot = 0;
    for (int i = 0;; ++i) {
        if (str[i] == 0)
            break;
        tot += val[str[i] - 1 - '0'];
    }
    printf("%d", tot);
    return 0;
}