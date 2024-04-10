#include <cstdio>
typedef long long int64;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int64 d, k, a, b, t;
int64 block_time_car, block_time_walk;

int64 calc()
{
    block_time_car = a * k + t;
    block_time_walk = b * k;
    if (d <= k) return a * d;
    d -= k;

    int64 blocks = d / k, remainder = d % k;
    int64 block_time_spent = blocks * block_time_car;
    int64 remainder_time_car = t + remainder * a;
    int64 remainder_time_walk = remainder * b;
    int64 use_car_in_blocks = block_time_spent + min(remainder_time_car, remainder_time_walk);

    int64 use_walk_in_blocks = d * b;
    return min(use_car_in_blocks, use_walk_in_blocks) + a * k;
}

int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d", &d, &k, &a, &b, &t);
    printf("%I64d\n", calc());
    return 0;
}