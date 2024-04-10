#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = (int) 1e9 + 7;

int main()
{
    int a, b, i;
    ll sum=0;

    scanf("%d%d", &a, &b);

    for (i=1; i<b; i++)
        sum = (((sum + ((((ll) a * (a+1)) / 2) % MOD) * (((ll)i * b) % MOD)) % MOD) + (ll) a * i) % MOD;

    printf("%I64d\n", sum);

    return 0;
}