#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

LL F(LL a, LL b, LL c) {
    return a * a * (b + c) + a * (b * b + c * c + 2 * b * c) + b * c * (b + c);
}

vector<LL> div(LL N) {
    LL a = 1;
    vector<LL> d;
    while (a * a < N) {
        if (N % a == 0) d.push_back(a);
        ++a;
    }
    if (N % a == 0) d.push_back(a);
    sort(d.begin(), d.end());
    return d;
}

void add(LL a, LL b, LL c, LL& r) {
    if (a == c) ++r;
    else
        if (a == b || b == c)
            r+=3;
        else
            r+=6;
}

int main() {
    LL N;
    cin >> N;
    LL res = 0;
    LL ans = 0;

    if (N % 3 == 0) {
        N /= 3;
        vector<LL> d = div(N);
        for (LL a = 1; 8 * a * a * a <= N; ++a) {
            for (size_t i = 0; i < d.size(); ++i) {
                LL b = d[i] - a;
                if (b < a) continue;
                if (N / b / b / b == 0 || F(a, b, b) > N) break;

                LL D = (a + b) * (a + b) - 4 * (a * b - N / (a + b));
                if (D < 0) continue;
                LL d = (LL)sqrt(D + 0.0);
                while (d * d < D) ++d;
                if (d * d != D) continue;
                if (d % 2 != (a+b) % 2) continue;
                LL c = (-(a+b) + d) / 2;
                if (c >= b)
                    add(a, b, c, res);
            }
        }
    }

    cout << res << endl;
    return 0;
}