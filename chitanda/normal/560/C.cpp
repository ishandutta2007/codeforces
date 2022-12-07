#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int a[7], t;

int ans;
int main(){
    for(int i = 1; i <= 6; i++) scanf("%d", a + i);
    t = min(a[1], a[3]);
    ans = (a[2] * 2 + 1) * t + t * (t - 1);
    t = min(a[4], a[6]);
    ans += (a[5] * 2 + 1) * t + t * (t - 1);
    ans += ((a[5] + t) * 2) * (max(a[4], a[6]) - t);
    printf("%d\n", ans);
    return 0;
}