#include <cstdlib>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <memory.h>
#include <numeric>
#include <utility>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

#include <cstring>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>

#define forit(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define clr(q) while (!q.empty()) q.pop()
#define alc(a, v) memset(a, v, sizeof(a))

#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct Point {
    int x, y, z;
    
    Point(int x = 0, int y = 0, int z = 0) :x(x), y(y), z(z){}
    void input() {
        scanf("%d%d%d", &x, &y, &z);
    }
    void Print() {
        printf("%d %d %d\n", x, y, z);
    }
    bool operator == (const Point& A) const {
        
        return x == A.x && y == A.y && z == A.z;
    }
    
}P[10][10], Q[10], R[10], S[10], T;
int flag;
int64 dist(Point& A, Point& B) {
    return (int64)(A.x - B.x) * (A.x - B.x) + (int64) (A.y - B.y) * (A.y - B.y) + (int64) (A.z - B.z) * (A.z - B.z);
}
int64 scala(Point& A, Point& B, Point& C) {
    return (int64)(A.x - B.x) * (C.x - B.x) + (int64)(A.y - B.y) * (C.y - B.y) + (int64)(A.z - B.z) * (C.z - B.z);
}

bool can() {
    int i, j, k;
    int64 D = LONG_LONG_MAX, dis[8];
    for (i = 1; i < 8; i ++) {
        dis[i] = dist(Q[0], Q[i]);
        D = min(D, dis[i]);
    }
    int sum[5]; sum[0] = 3, sum[1] = 3, sum[2] = 1;
    int cn[5];
    memset(cn, 0, sizeof cn);
    for (i = 1; i < 8; i ++) {
        if (dis[i] == D) {
            sum[0] --;
            S[cn[0] ++] = Q[i];
        } else if (dis[i] == 2 * D) {
            sum[1] --;
            R[cn[1] ++] = Q[i];
        } else if (dis[i] == 3 * D) {
            sum[2] --;
            T = Q[i];
        }
    }
    if (sum[0] != 0 || sum[1] != 0 || sum[2] != 0) return false;
    
    for (i = 0; i < 3; i ++) {
        for (j = i + 1; j < 3; j ++) {
            if (scala(S[i], Q[0], S[j]))return false;
        }
    
    }

    int chk[5];
    for (i = 0; i < 3; i ++) chk[i] = 0;
    for (i = 0; i < 3; i ++) {
        for (j = i + 1; j < 3; j ++) {
            Point tmp = Point(S[i].x + S[j].x - Q[0].x, S[i].y + S[j].y - Q[0].y, S[i].z + S[j].z - Q[0].z);
            for (k = 0; k < 3; k ++) if (!chk[k]) {
                if (tmp == R[k]) {
                   chk[k] = 1;
                   break;
                }
            }
        }
        
    }
    for (k = 0; k < 3; k ++) if (!chk[k]) return false;
    Point tmp = Point(S[0].x + S[1].x + S[2].x - 2 * Q[0].x, S[0].y + S[1].y + S[2].y - 2 * Q[0].y, S[0].z + S[1].z + S[2].z - 2 * Q[0].z);
    if (T == tmp) return true;
    return false;
}
void calc(int step) {
    if (flag) return;
    if (step == 8) {
        if (can()) {
           flag = 1;
           puts("YES");
           for (int i = 0; i < 8; i ++) Q[i].Print();
        }
        return;
    }
    for (int i = 0; i < 6 && !flag; i ++) {
        Q[step] = P[i][step];
        calc(step + 1);
    }
}

main() {
    
    int i;
    for (i = 0; i < 8; i ++) {
        P[0][i].input();
    }
    for (i = 1; i < 8; i ++) {
        P[1][i] = Point(P[0][i].x, P[0][i].z, P[0][i].y);
        P[2][i] = Point(P[0][i].y, P[0][i].x, P[0][i].z);
        P[3][i] = Point(P[0][i].y, P[0][i].z, P[0][i].x);
        P[4][i] = Point(P[0][i].z, P[0][i].y, P[0][i].x);
        P[5][i] = Point(P[0][i].z, P[0][i].x, P[0][i].y);
    }
    Q[0] = P[0][0];
    calc(1);
    if (!flag) {
        puts("NO");
    }
}