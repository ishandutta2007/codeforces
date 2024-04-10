#include <cstdio>
#include <algorithm>
#include <functional>
typedef long long int64;
static const int MAXN = 100006;

int n;
int a1, b1, a2, b2;
std::pair<int, int> photos[MAXN * 2];
int photos_val[MAXN * 2];
int photo_ct = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        if (a1 + b1 >= a2 + b2) {
            photos[photo_ct++] = std::make_pair(a1, b1);
            photos[photo_ct++] = std::make_pair(a2, b2);
        } else if (a1 > b2) {
            photos[photo_ct++] = std::make_pair(a1 - b2, b2 - a1);
        } else if (b1 > a2) {
            photos[photo_ct++] = std::make_pair(a2 - b1, b1 - a2);
        }
    }

    int64 ans = 0;
    for (int i = 0; i < photo_ct; ++i) {
        ans += photos[i].first - photos[i].second;
        photos_val[i] = photos[i].first + photos[i].second;
    }
    std::sort(photos_val, photos_val + photo_ct, std::greater<int>());
    for (int i = 0; i < photo_ct; ++i)
        if (i % 2 == 0) ans += photos_val[i]; else ans -= photos_val[i];

    printf("%I64d\n", ans / 2);
    return 0;
}