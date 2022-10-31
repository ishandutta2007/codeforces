#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long a, b;
long long ans = 0;

int main() {
    scanf("%I64d %I64d", &a, &b);
    while(a && b) {
        if (a == b) {
            a = b = 0;
            ans++;
            continue;
        }
        if (a > b) {
            ans += a / b;
            a = a % b;
            continue;
        }
        if (a < b) {
            swap(a, b);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}