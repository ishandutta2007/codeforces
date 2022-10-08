#include <stdio.h>
#include <algorithm>
using namespace std;
char d1[1050];
char d2[1050];
int main() {
    int N, i;
    scanf("%d", &N);
    scanf("%s %s", d1, d2);

    int ans = 0;
    for(i = 0; i < N; i++) {
        ans += (abs(d1[i]-d2[i]) < 5)? abs(d1[i]-d2[i]):10-abs(d1[i]-d2[i]);
    }
    printf("%d", ans);
    return 0;
}