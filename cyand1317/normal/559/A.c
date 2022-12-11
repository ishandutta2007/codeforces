#include <stdio.h>
#include <math.h>
#define EPS 1e-4

int main()
{
    double a[6];
    int i, j, x;
    for (i = 0; i < 6; ++i) scanf("%lf", &a[i]);
    int turn[6], cur_turn;
    unsigned char valid;
    float px[6], py[6];
    int ans = -1, cur_ans;
    for (x = 0; x < (1 << 10); ++x) {
        for (i = 1; i < 6; ++i) turn[i] = (x >> (i + i)) & 3;
        px[0] = py[0] = cur_turn = 0;
        for (i = 1; i < 6; ++i) {
            switch (turn[i]) {
                case 0: cur_turn += 60; break;
                case 1: cur_turn += 120; break;
                case 2: cur_turn += 240; break;
                case 3: cur_turn += 300; break;
            }
            px[i] = px[i - 1] + a[i] * cos((double)cur_turn * M_PI / 180.0);
            py[i] = py[i - 1] + a[i] * sin((double)cur_turn * M_PI / 180.0);
            valid = 1;
            for (j = 0; j < i; ++j)
                if (fabs(px[i] - px[j]) < EPS && fabs(py[i] - py[j]) < EPS) {
                    valid = 0; break;
                }
            if (!valid) break;
        }
        if (valid && fabs(px[5] * px[5] + py[5] * py[5] - a[0] * a[0]) > EPS) valid = 0;
        if (valid && fabs((px[4] - px[0]) * (py[5] - py[0]) - (py[4] - py[0]) * (px[5] - px[0])) < EPS) valid = 0;
        if (valid) {
            double area = 0;
            for (i = 0; i < 6; ++i)
                area += (px[i] * py[(i + 1) % 6] - py[i] * px[(i + 1) % 6]) / 2.0;
            cur_ans = (int)round(fabs(area) / (sqrt(3.0) / 4.0));
            if (ans < cur_ans) ans = cur_ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}