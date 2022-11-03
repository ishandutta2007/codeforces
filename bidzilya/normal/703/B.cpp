#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }

    vector<bool> cap(n, false);
    vector<int> caps;
    caps.reserve(k);
    for (int i = 0; i < k; ++i) {
        int v;
        scanf("%d", &v);
        --v;
        cap[v] = true;
        caps.push_back(v);
    }

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        if (j == n) {
            j = 0;
        }

        if (!cap[i] && !cap[j]) {
            result += 1LL * c[i] * c[j];
        }
    }

    long long allSum = 0;
    for (int i = 0; i < n; ++i) {
        allSum += c[i];
    }

    for (int v : caps) {
        result += 1LL * (allSum - c[v]) * c[v];
    }

    long long capSum = 0;
    for (int v : caps) {
        result -= 1LL * capSum * c[v];
        capSum += c[v];
    }

    printf(LLD_SPEC "\n", result);

    return 0;
}