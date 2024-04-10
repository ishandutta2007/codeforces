#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll Rijesi(ll a, ll b)
{
    if (!b)
        return 0;
    return a / b + Rijesi(b, a%b);
}

int main()
{
    ll a, b;

    scanf("%I64d %I64d", &a, &b);
    printf("%I64d\n", Rijesi(max(a, b), min(a, b)));

    return 0;
}