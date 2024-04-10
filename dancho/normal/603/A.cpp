#include <cstdio>
#include <cstring>

int n;
char a[1 << 20];

int main() {
    scanf("%d", &n);
    scanf("%s", a);
    int dif = 0;
    int sm = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            ++dif;
        } else if (a[i] == a[i - 1]) {
            ++sm;
        }
    }
    if (sm > 2) {
        sm = 2;
    }
    printf("%d\n", 1 + dif + sm);
    return 0;
}