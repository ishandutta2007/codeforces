#include <iostream>
#include <cstdio>

using namespace std;

int x[8], y[8];

int dx(int a, int b) {
    return x[b] - x[a];
}

int dy(int a, int b) {
    return y[b] - y[a];
}

int dist2(int a, int b) {
    return (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
}

bool square(int a, int b, int c, int d) {
    if(dy(a, b) != -dx(b, c)) return 0;
    if(dx(a, b) != dy(b, c)) return 0;
    if(dy(b, c) != -dx(c, d)) return 0;
    if(dx(b, c) != dy(c, d)) return 0;
    if(dy(c, d) != -dx(d, a)) return 0;
    if(dx(c, d) != dy(d, a)) return 0;
    if(dy(d, a) != -dx(a, b)) return 0;
    if(dx(d, a) != dy(a, b)) return 0;
    return 1;
}


bool rect(int a, int b, int c, int d) {
    if(dy(a, b) != -dy(c, d)) return 0;
    if(dx(a, b) != -dx(c, d)) return 0;
    if(dy(b, c) != -dy(d, a)) return 0;
    if(dx(b, c) != -dx(d, a)) return 0;
    if(dist2(c,b) + dist2(c,d) != dist2(b, d)) return 0;
    return 1;
}

int main() {
    // freopen("1.in", "r", stdin);
    for(int i = 0; i < 8; ++i)
        cin >> x[i] >> y[i];
    for(int a = 0; a < 8; ++a) {
        for(int b = 0; b < 8; ++b) {
            if(a == b) continue;
            for(int c = 0; c < 8; ++c) {
                if(a == c || b == c) continue;
                for(int d = 0; d < 8; ++d) {
                    if(a == d || b == d || c == d) continue;
                    if(!square(a, b, c, d)) continue;
                    for(int x = 0; x < 8; ++x) {
                        if(x == a || x == b || x == c || x == d) continue;
                        for(int y = 0; y < 8; ++y) {
                            if(y == a || y == b || y == c || y == d || y == x) continue;
                            for(int z = 0; z < 8; ++z) {
                                if(z == a || z == b || z == c || z == d || z == x || z == y) continue;
                                for(int r = 0; r < 8; ++r) {
                                    if(r == a || r == b || r == c || r == d || r == x || r == y || r == z) continue;
                                    if(rect(x,y,z,r)) {
                                        cout << "YES\n";
                                        cout << ++a << " " << ++b << " " << ++c << " " << ++d << "\n";
                                        cout << ++x << " " << ++y << " " << ++z << " " << ++r << "\n";
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}