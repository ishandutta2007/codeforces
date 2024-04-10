#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

struct PT {
    long long x, y;
    PT(long long x = 0, long long y = 0) : x(x), y(y) {}
    bool operator<(const PT &rhs) const {
    	return x < rhs.x || x == rhs.x && y < rhs.y;
    }
};

long long cross(PT p, PT p1, PT p2) {
	return (p1.x - p.x) * (p2.y - p.y) - (p2.x - p.x) * (p1.y - p.y);
}

int convex_hull(vector<PT> &P) {
    sort(P.begin(), P.end());
    int n = P.size();
    vector<PT> Q(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (m && Q[m - 1].x == P[i].x) m--;
        Q[m++] = P[i];
    }
    swap(n, m);
    Q.resize(n);
    m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && cross(P[m - 2], P[m - 1], Q[i]) >= 0) m--;
        P[m++] = Q[i];
    }
    return m - 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
	vector<PT> P(n);
    for (int i = 0; i < n; i++) cin >> P[i].x >> P[i].y, P[i].x *= -1, P[i].y -= P[i].x * P[i].x;
    cout << convex_hull(P) << endl;
	return 0;
}