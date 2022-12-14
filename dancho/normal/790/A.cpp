#include <cstdio>
#include <cstring>

char ok[64][64];
int name[64];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k - 1; ++i) {
        name[i] = i;
    }
    for (int i = 0; i < n - k + 1; ++i) {
        scanf("%s", ok[i]);
        int j = i + k - 1;
        if (ok[i][0] == 'Y') {
            name[j] = k + i;
        } else {
            name[j] = name[j - k + 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        char f = 'A' + name[i] % 26;
        char s = 'a' + name[i] / 26;
        printf("%c%c%c", f, s, " \n"[i + 1 == n]);
    }
    return 0;
}