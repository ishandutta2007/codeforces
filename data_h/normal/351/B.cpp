#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 3333;

int a[N];
double ans = 0;
int n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);     
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if (a[i] > a[j])
                cnt++;
    if (cnt % 2 == 0)
        printf("%.6f\n", 2.0 * cnt);
    else
        printf("%.6f\n", 2.0 * cnt - 1);
    return 0;
}