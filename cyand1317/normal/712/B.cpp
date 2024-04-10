#include <cstdio>
template <typename T> inline T abs(const T x) { return x > 0 ? x : -x; }

int ct[128] = { 0 };
bool valid[128] = { false };

int main()
{
    valid['L'] = valid['R'] = valid['U'] = valid['D'] = true;
    char ch;
    while (valid[(ch = getchar())]) ++ct[ch];

    if ((ct['L'] + ct['R'] + ct['U'] + ct['D']) % 2 == 1) {
        puts("-1");
    } else {
        int ans = abs(ct['L'] - ct['R']) / 2 + abs(ct['U'] - ct['D']) / 2;
        if ((ct['L'] + ct['R']) % 2 == 1) ++ans;
        printf("%d\n", ans);
    }

    return 0;
}