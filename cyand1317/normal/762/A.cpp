#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long int64;

int64 n;
int k;
std::vector<int64> small, large;

int main()
{
    scanf("%I64d%d", &n, &k);

    for (int64 i = 1; i * i <= n; ++i) if (n % i == 0) {
        small.push_back(i);
        if (i * i != n) large.push_back(n / i);
    }
    std::reverse(large.begin(), large.end());

    --k;
    if (k < (int)small.size()) printf("%I64d\n", small[k]);
    else {
        k -= (int)small.size();
        if (k < (int)large.size()) printf("%I64d\n", large[k]);
        else puts("-1");
    }

    return 0;
}