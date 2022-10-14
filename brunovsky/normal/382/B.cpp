#include <bits/stdc++.h>

using namespace std;

#define long long long

// *****

struct State {
    long a, b, w, x, c;
    long steps = 0;

    void print() { printf("%lld: a=%lld b=%lld c=%lld\n", steps, a, b, c); }
    void read() { cin >> a >> b >> w >> x >> c; }
    bool ahead() { return c <= a; }

    void advance() {
        c = c - 1;
        if (b >= x) {
            b = b - x;
        } else {
            a = a - 1;
            b = w - (x - b);
        }
        steps++;
    }
};

auto solve() {
    State start;
    start.read();

    if (start.ahead()) {
        return 0LL;
    }

    State cur = start;
    do {
        cur.advance();
        if (cur.ahead()) {
            return cur.steps;
        }
    } while (cur.b != start.b);

    long da = start.a - cur.a;
    long dc = start.c - cur.c;
    long steps = cur.steps;
    assert(dc == steps && dc > da);

    long k = (start.c - start.a) / (dc - da) - 1;

    // advance start k * steps times
    cur = start;
    cur.a = start.a - k * da;
    cur.c = start.c - k * dc;
    cur.steps = k * steps;

    while (!cur.ahead()) {
        cur.advance();
    }

    return cur.steps;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}