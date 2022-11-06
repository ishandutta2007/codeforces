#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int all = a + b + c;
        int x =  max((all + 2) / 2, a), y = all - b;
        printf("%d\n", max(0, y - x + 1));
    }
    return 0;
}