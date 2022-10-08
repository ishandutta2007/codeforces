//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 524288;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

struct Point {
    int x, y;
    Point() {
        Point(0, 0);
    }
    Point(int a, int b) {
        x = a, y = b;
    }
    Point minus(Point k) {
        return Point(x - k.x, y - k.y);
    }

    bool operator < (const Point & l) const {
        int x1 = x, y1 = y, x2 = l.x, y2 = l.y;
        if (y1 < 0) {
            x1 *= -1;
            y1 *= -1;
        }
        if (y2 < 0) {
            x2 *= -1;
            y2 *= -1;
        }
        if (y2 == 0) return false;
        if (y1 == 0) return true;
        return x1*y2 < x2*y1;
    }
    
    bool operator == (const Point & l) const {
        if (y == 0) {
            if (l.y == 0) return true;
            else return false;
        }
        return x*l.y == y*l.x;
    }
};

Point in[2050];
vector <Point> V;
int main() {
    int N, i, j, t1, t2;
    scanf("%d", &N);
    if (N <= 2) {
        printf("0");
        return 0;
    }

    ll cnt = 0;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &t1, &t2);
        in[i] = Point(t1, t2);
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (j == i) continue;
            V.push_back(in[j].minus(in[i]));
        }
        sort(V.begin(), V.end());
        int st = 0;
        for (j = 1; j < V.size(); j++) {
            if (V[j] == V[st]) continue;
            cnt += (j - st)*(j - st-1)/2;
            st = j;
        }
        cnt += ((int)V.size() - st)*((int)V.size() - st-1)/2;
        V.clear();
    }
    printf("%I64d", (ll)N*(N - 1)*(N - 2) / 6 - cnt / 3);
    return 0;
}

//*/