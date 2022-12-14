#include <cstdio>
#include <cstring>

char buf[1024];

int n;

int main() {
    fgets(buf, 1024, stdin);
    sscanf(buf, "%d", &n);
    int ans = 0;
    if (strstr(buf, "w") == NULL) {
        // Not found -> month
        //
        if (n <= 29) {
            ans = 12;
        } else if (n == 30) {
            ans = 11;
        } else if (n == 31) {
            ans = 7;
        }
    } else {
        ans = 52;
        if (n == 5 || n == 6) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}