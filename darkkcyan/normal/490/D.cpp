#include <bits/stdc++.h>

using namespace std;

const string FILE_NAME = "chocolate";

#define loop(i, a, b, c) for (i = a; i < b; i += c)
#define rloop(i, a, b, c) for (i = a; i > b; i += c)
#define loop0(i, a, b, c) loop1(i, a, b + 1, c)
#define rloop0(i, a, b, c) loop1(i, a - 1, b, c)

class Chocolate {
public:
    int w;
    int h;
    int w2, w3;
    int h2, h3;
    int hr, wr;

    void parse() {
        hr = h;
        wr = w;
        w2 = w3 = h2 = h3 = 0;
        while (hr % 2 == 0) {
            hr /= 2;
            h2++;
        }
        while (hr % 3 == 0) {
            hr /= 3;
            ++h3;
        }
        while (wr % 2 == 0) {
            wr /= 2;
            ++w2;
        }
        while (wr % 3 == 0) {
            wr /= 3;
            ++w3;
        }
    }

    inline int get2() {
        return w2 + h2;
    }

    inline int get3() {
        return w3 + h3;
    }

    inline int getAll() {
        return get2() + get3();
    }

    inline int getR() {
        return wr * hr;
    }

    int sub2(int val) {
        int cost = 0;
        if (w2 >= val) {
            w2 -= val;
            return cost + val;
        }
        val -= w2;
        cost += w2;
        w2 = 0;

        if (h2 >= val) {
            h2 -= val;
            return cost + val;
        }
        val -= h2;
        cost += h2;
        h2 = 0;

        if (w3 >= val) {
            w3 -= val;
            return cost + val * 2;
        }
        val -= w3;
        cost += w3 * 2;
        w3 = 0;

        if (h3 >= val) {
            h3 -= val;
            return cost + val * 2;
        }
        return -1;  // cant sub
    }

    int convert3to2(int val) {
        int cost = 0;
        if (w3 >= val) {
            w3 -= val;
            w2 += val;
            return cost + val;
        }
        val -= w3;
        w2 += w3;
        cost += w3;
        w3 = 0;
        if (h3 >= val) {
            h3 -= val;
            h2 += val;
            return cost + val;
        }
        return -1;
    }

    int reConstruct() {
        h = hr;
        w = wr;
        int i;
        for (i = 0; i < h2; ++i) {
            h *= 2;
        }
        for (i = 0; i < h3; ++i) {
            h *= 3;
        }
        for (i = 0; i < w2; ++i) {
            w *= 2;
        }
        for (i = 0; i < w3; ++i) {
            w *= 3;
        }
    }
};

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;
    #ifndef ONLINE_JUDGE
    ifstream cin((FILE_NAME + ".inp").c_str());
    ofstream cout((FILE_NAME + ".out").c_str());
    #endif

    Chocolate a, b;
    cin >> a.w >> a.h >> b.w >> b.h;

    a.parse();
    b.parse();
    if (a.getR() != b.getR()) {
        cout << -1 << '\n';
        return 0;
    }

    int cost = 0;
    clog << a.get2() << ' ' << a.get3() << '\n';
    clog << b.get2() << ' ' << b.get3() << '\n';
    if (a.getAll() > b.getAll()) {
        cost += a.sub2(a.getAll() - b.getAll());
    } else {
        cost += b.sub2(b.getAll() - a.getAll());
    }

    clog << cost << '\n';
    clog << a.get2() << ' ' << a.get3() << '\n';
    clog << b.get2() << ' ' << b.get3() << '\n';
    if (a.get3() > b.get3()) {
        cost += a.convert3to2(a.get3() - b.get3());
    } else {
        cost += b.convert3to2(b.get3() - a.get3());
    }

    clog << a.get2() << ' ' << a.get3() << '\n';
    clog << b.get2() << ' ' << b.get3() << '\n';
    a.reConstruct();
    b.reConstruct();

    cout << cost << '\n';
    cout << a.w << ' ' << a.h << '\n';
    cout << b.w << ' ' << b.h << '\n';

    return 0;
}