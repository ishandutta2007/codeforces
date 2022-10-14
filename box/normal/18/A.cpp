#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

bool isright(double a, double b, double c) {
    double mx = max(a, max(b, c));
    if(a == mx) {
        a = b; b = c; c = mx;
    } else if(b == mx) {
        b = c; c = mx;
    }
    if(a + b == c) return false;
    return abs((a*a+b*b)-(c*c)) <= 1e-5;
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

double d(int x1, int y1, int x2, int y2) {
    return sqrt((double)((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

int main() {
    int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(isright(d(x1,y1,x2,y2),d(x1,y1,x3,y3),d(x2,y2,x3,y3))) {
        cout << "RIGHT" << endl;
        return 0;
    }
    for(int i=0; i<4; i++) {
        x1 += dx[i]; y1 += dy[i];
        if(isright(d(x1,y1,x2,y2),d(x1,y1,x3,y3),d(x2,y2,x3,y3))) {
            cout << "ALMOST" << endl;
            return 0;
        }
        x1 -= dx[i]; y1 -= dy[i];
    }
    for(int i=0; i<4; i++) {
        x2 += dx[i]; y2 += dy[i];
        if(isright(d(x1,y1,x2,y2),d(x1,y1,x3,y3),d(x2,y2,x3,y3))) {
            cout << "ALMOST" << endl;
            return 0;
        }
        x2 -= dx[i]; y2 -= dy[i];
    }
    for(int i=0; i<4; i++) {
        x3 += dx[i]; y3 += dy[i];
        if(isright(d(x1,y1,x2,y2),d(x1,y1,x3,y3),d(x2,y2,x3,y3))) {
            cout << "ALMOST" << endl;
            return 0;
        }
        x3 -= dx[i]; y3 -= dy[i];
    }
    cout << "NEITHER" << endl;
}