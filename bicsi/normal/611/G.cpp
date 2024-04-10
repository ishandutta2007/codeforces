#include <iostream>
#include <algorithm>

using namespace std;



typedef long long ull;
typedef pair<ull, ull> Point;


#define x first
#define y second

ull cross(Point A, Point B) {
    return A.x * B.y - A.y * B.x;
}

Point P[2000005];

ull s1 = 0, s2 = 0;
Point S;
int i, j;

const ull MOD = 1e9 + 7;

void ins() {
    s1 += cross(P[j], P[j+1]);
    s2 += s1 % MOD;
    if(s2 < 0) s2 += MOD;
    if(s2 >= MOD) s2 -= MOD;

    S.x += P[j+1].x;
    S.y += P[j+1].y;

    S.x %= MOD;
    S.y %= MOD;

    while(S.x < 0) S.x += MOD;
    while(S.y < 0) S.y += MOD;

    j += 1;
}

void ers() {
    s2 -= cross(P[i], P[i+1]) % MOD * (j - i) % MOD;
    s1 -= cross(P[i], P[i+1]);
    if(s2 < 0) s2 += MOD;
    if(s2 >= MOD) s2 -= MOD;

    S.x -= P[i].x;
    S.y -= P[i].y;

    S.x %= MOD;
    S.y %= MOD;

    while(S.x < 0) S.x += MOD;
    while(S.y < 0) S.y += MOD;

    i += 1;
}

void Read(int &x) {
    char c, sgn = 0;
    for(c = getchar(); !isdigit(c) && c != '-'; c = getchar());
    if(c == '-') sgn = 1, c = getchar();
    for(x = 0; isdigit(c); c= getchar()) x = x * 10 + c - '0';
    if(sgn) x = -x;
}

int main() {

    int n, a, b;
    ull Aria = 0;
    Read(n);

    for(int i=1; i<=n; i++) {
        Read(a); Read(b);
        P[i] = Point(a, b);
    }

    reverse(P+1, P+n+1);

    for(int i=1; i<=n; i++) {
        P[i+n] = P[i+2*n] = P[i];
        Aria += cross(P[i-1], P[i]);
    }
    Aria += cross(P[n], P[1]);
    S = P[1];

    j = 1;

    ull total = 0;

    for(i=1; i<=n;) {
        while( (s1 + cross(P[j], P[j+1]) + cross(P[j+1], P[i])) <= Aria / 2)
            ins();

        if(j <= n && 2LL * (s1 + cross(P[j], P[i])) == Aria)
            total -= (Aria / 2) % MOD;

        Point pr(P[i].x % MOD, P[i].y % MOD);

        total += s2 + cross(S, pr);
        total %= MOD;

        ers();
    }

    if(total < 0) total += MOD;
    total = (ull) n * (n - 3) / 2 % MOD * (Aria % MOD) % MOD - 2 * total;
    total %= MOD;
    if(total < 0) total += MOD;

    cout << total;
    return 0;
}