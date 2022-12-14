#include <cstdio>
#include <cstring>
#include <vector>

int n;
int v[1 << 20];
int d[1 << 20];
int p[1 << 20];
int us[1 << 20];

void leave(int j);

void treat(int i) {
    us[i] = 1;
    int k = v[i];
    std::vector<int> tocry;
    for (int j = i + 1; j < n; ++j) {
        if (!us[j] && k > 0) {
            p[j] -= k;
            --k;
            if (p[j] < 0) {
                tocry.push_back(j);
            }
        }
    }
    for (int k = 0; k < (int) tocry.size(); ++k) {
        leave(tocry[k]);
    }
}

void leave(int i) {
    if (us[i]) return;
    us[i] = 1;
    for (int j = i + 1; j < n; ++j) {
        if (!us[j]) {
            p[j] -= d[i];
            if (p[j] < 0) {
                leave(j);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &v[i], &d[i], &p[i]);
    }
    memset(us, 0, sizeof(us));
    std::vector<int> cu;
    for (int i = 0; i < n; ++i) {
        if (!us[i] && p[i] >= 0) {
            treat(i);
            cu.push_back(i + 1);
        }
    }
    printf("%d\n", (int) cu.size());
    for (int i = 0; i < (int) cu.size(); ++i) {
        printf("%d%c", cu[i], " \n"[i + 1 == (int) cu.size()]);
    }
    return 0;
}