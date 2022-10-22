#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const int MN = 1e5+2, MOD = 1e9+7, BASH = 100;
const ld EPS = 1e-12;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int rand (int a, int b) {
    return uniform_int_distribution<int>(a,b)(rnd);
}
pii points[MN];
bool in[MN];
int main () {
    int n;
    scanf ("%d",&n);
    if (n <= 2) return !printf ("YES\n");
    for (int i = 1; i <= n; i++) {
        scanf ("%d %d",&points[i].first,&points[i].second);
    }
    for (int att = 1; att <= BASH; att++) {
        int f = rand(1,n),s;
        do {
            s = rand(1,n);
        } while (s == f);
        int x1 = points[f].first, x2 = points[s].first, y1 = points[f].second, y2 = points[s].second;
        bool vert = x1 == x2;
        ld m=-1,b=-1;
        if (!vert) {
            m = (y2-y1)/(ld)(x2-x1);
            b = y1-m*x1;
        }
        memset(in,0,sizeof in);
        for (int i = 1; i <= n; i++) if ((vert && points[i].first == x1) || (!vert && abs(m*points[i].first+b-points[i].second) < EPS)) in[i] = 1;
        f = 0; s = 0;
        for (int i = 1; i <= n; i++) {
            if (!in[i]) {
                if (!f) f = i;
                else if (!s) {
                 s = i;
                 break;   
                }
            }
        }
        if (s == 0) return !printf ("YES\n");
        x1 = points[f].first, x2 = points[s].first, y1 = points[f].second, y2 = points[s].second;
        vert = x1 == x2;
        m=-1,b=-1;
        if (!vert) {
            m = (y2-y1)/(ld)(x2-x1);
            b = y1-m*x1;
        }
        for (int i = 1; i <= n; i++) if ((vert && points[i].first == x1) || (!vert && abs(m*points[i].first+b-points[i].second) < EPS)) in[i] = 1;
        bool good = 1;
        for (int i = 1; i <= n; i++) if (!in[i]) good = 0;
        if (good) return !printf ("YES\n");
    }
    return !printf("NO\n");
}