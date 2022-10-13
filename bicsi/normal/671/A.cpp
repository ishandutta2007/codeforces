#include <bits/stdc++.h>

using namespace std;
typedef complex<double> Point;

double dist(Point A, Point B) {
    return abs(A - B);
}

Point P[500000];
int IA[500000], IB[500000];

void Read(Point &x) {
    int a, b;
    scanf("%d%d", &a, &b);
    x = Point(a, b);
}

int main() {
    int n;
    Point A, B, Bin;

    Read(A); Read(B); Read(Bin);


    scanf("%d", &n);
    double total = 0;
    for(int i = 1; i <= n; ++i) {
        Read(P[i]);
        total += dist(P[i], Bin);
        IA[i] = IB[i] = i;
    }
    total *= 2;


    sort(IA + 1, IA + n + 1, [&](int a, int b) {
        return dist(A, P[a]) - dist(Bin, P[a]) < dist(A, P[b]) - dist(Bin, P[b]);
    });


    sort(IB + 1, IB + n + 1, [&](int a, int b) {
        return dist(B, P[a]) - dist(Bin, P[a]) < dist(B, P[b]) - dist(Bin, P[b]);
    });

    //Se duce a la cel mai bun
    double ans = dist(A, P[IA[1]]) - dist(Bin, P[IA[1]]);
    ans = min(ans, dist(B, P[IB[1]]) - dist(Bin, P[IB[1]]));
    
    if(n >= 2) {
        for(int i = 1; i <= 2; ++i)
        for(int j = 1; j <= 2; ++j) {
            if(IA[i] == IB[j]) continue;
            ans = min(ans, dist(A, P[IA[i]]) - dist(Bin, P[IA[i]]) + dist(B, P[IB[j]]) - dist(Bin, P[IB[j]]));
        }
    }

    cout << fixed << setprecision(12) << total + ans;


    return 0;
}