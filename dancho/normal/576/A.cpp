#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> sl;
    scanf("%d", &n);

    for (int i = 2; i <= n; ++i) {
        bool ok = true;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                ok = false;
            }
        }
        if (ok) {
            int k = i;
            while (k <= n) {
                sl.push_back(k);
                k *= i;
            }
        }
    }

    printf("%d\n", (int) sl.size());
    for (int i = 0; i < (int) sl.size(); ++i) {
        printf("%d%c", sl[i], " \n"[i == (int) sl.size() - 1]);
    }
    return 0;
}