#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;

unordered_map<int, int> cnt;
int n;

int a[1024];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    int best = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            cnt[a[i]]--;
            cnt[a[j]]--;
            int x, y;
            x = a[i];
            y = a[j];
            int cs = 0;
            while ((x != 0 || y != 0) && cnt[x + y]) {
                int nx, ny;
                nx = y;
                ny = x + y;
                cnt[x + y]--;
                x = nx;
                y = ny;
                ++cs;
            }
            best = max(best, cs + 2 + cnt[x + y]);
            x = a[i];
            y = a[j];
            cnt[x]++;
            cnt[y]++;
            while (cs) {
                int nx, ny;
                nx = y;
                ny = x + y;
                cnt[x + y]++;
                x = nx;
                y = ny;
                --cs;
            }
        }
    }

    printf("%d\n", best);

    return 0;
}