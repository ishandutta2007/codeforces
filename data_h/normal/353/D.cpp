#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1111111;

char buf[N];
int n, ans = 0, f[N], wait[N], preBoy[N];

int main() {
    scanf("%s", buf + 1);
    n = strlen(buf + 1);
    int countBoy = 0, countGirl = 0, prePos = 0;
    for(int i = 1; i <= n; i++) {
        if (buf[i] == 'M') {
            countBoy++;
        } else if (buf[i] == 'F') {
            if (prePos == 0) {
                f[i] = countBoy;
            } else {
                if (countBoy > f[prePos]) {
                    f[i] = countBoy;
                } else {
                    f[i] = f[prePos] + 1;
                }
            }
            if (countBoy)
                prePos = i;
            ans = max(ans, f[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}