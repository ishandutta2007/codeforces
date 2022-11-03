#include <bits/stdc++.h>
using namespace std;

long long C, Hr, Hb, Wr, Wb;

long long GetFunc(long long r, long long b)
{
    return r * Wr + b * Wb;
}

long long GetFuncR(long long r)
{
    return GetFunc(r, (C - Hr * r) / Hb);
}

long long GetFuncB(long long b)
{
    return GetFunc((C - Hb * b) / Hr, b);
}

long long GetGCD(long long a, long long b, long long& ta, long long& tb)
{
    if (a == 0) {
        ta = 0;
        tb = 1;
        return b;
    }
    long long ta1, tb1;
    long long d = GetGCD(b % a, a, ta1, tb1);
    ta = tb1 - (b / a) * ta1;
    tb = ta1;
    return d;
}

// find min x: a * x = b (c) for x >= l
long long Solve(long long a, long long b, long long c, long long l)
{
    b %= c;
    a %= c;
    if (a == 0) {
        if (b == 0) {
            return l;
        } else {
            return -1;
        }
    } else {
        b -= (a * l) % c;
        if (b < 0) {
            b += c;
        }
        long long ta, tc;
        long long g = GetGCD(a, c, ta, tc);
        if (g != 1) {
            if (b % g != 0) {
                return -1;
            } else {
                a /= g;
                b /= g;
                c /= g;
            }
        }
        ta %= c;
        if (ta < 0) {
            ta += c;
        }
        return (ta * b) % c + l;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> C >> Wr >> Wb >> Hr >> Hb;

    if (Wr * Hb - Wb * Hr < 0) {
        swap(Wr, Wb);
        swap(Hr, Hb);
    }

    long long sqC = sqrt(C);

    if (Hb >= sqC) {
        long long answer = 0;
        for (long long b = 0; b * Hb <= C; ++b) {
            answer = max(answer, GetFuncB(b));
        }
        cout << answer << endl;
    } else {
        long long answer = 0;
        long long r_max = C / Hr;
        for (long long T = 0; T < Hb && T <= C; ++T) {
            long long CC = C - T;
            long long kright = (C - T) / Hb;
            long long kleft = (C - T - Hr * r_max) / Hb;
            if (kleft * Hb < C - T - Hr * r_max) {
                ++kleft;
            }
            if (kleft < 0) {
                kleft = 0;
            }
            if (kleft <= kright) {
                long long k = Solve(Hb, CC, Hr, kleft);

                if (k != -1 && k <= kright) {
                    answer = max(answer, GetFuncR((C - T - Hb * k) / Hr));
                }
            }
        }
        cout << answer << endl;
    }

    return 0;
}