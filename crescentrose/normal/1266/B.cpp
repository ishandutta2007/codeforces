#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T;
long long t;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%lld", &t);
        t % 14 >= 1 && t % 14 <= 6 && t > 14?printf("YES\n"):printf("NO\n");
    }
    return 0;
}