#include <stdio.h>
#include <algorithm>
#define eps 0.00000001
#define x first
#define y second
#define point pair <int, int>

using namespace std;

point x[301];

inline double ccw(point A, point B, point C) {
    return ((double)(B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x)) * 0.5;
}

inline double chmax(double &A, double B) {
    if (B - A > eps)
        A = B;
}

int main() {
    int n;
    double maxArea = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i].x, &x[i].y);
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            double maxMinus = -1, maxPlus = -1;
            for (int k = 1; k <= n; ++k)
                if (k != i && k != j)
                    if (ccw(x[i], x[j], x[k]) < 0)
                        chmax(maxMinus, -ccw(x[i], x[j], x[k]));
                    else
                        chmax(maxPlus, ccw(x[i], x[j], x[k]));
            if (maxPlus >= 0 && maxMinus >= 0)
                    chmax(maxArea, maxMinus + maxPlus);
        }

    printf("%lf", maxArea);
    return 0;
//what a question
}