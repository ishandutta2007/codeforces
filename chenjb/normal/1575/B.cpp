#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double FLT;
typedef pair<int,int> pii;
typedef pair<FLT, FLT> pdd;
typedef pair<FLT, int> event;
int n, k;
vector<pii> p;
const FLT pi = acos(-1);
const FLT eps = 1e-9;
bool check(FLT R) {
    //vector<pdd> rg;
    vector<event> e;
    int S = 0;
    for (auto &t : p) {
        FLT dis = 1.0 * t.first * t.first + 1.0 * t.second * t.second;
        if (dis > 4 * R * R + eps) continue;
        //printf("ok %d %d\n",t.first,t.second);
        FLT theta = acos(sqrt(dis) / 2 / R);
        FLT alpha = atan2(t.second, t.first);
        if (alpha < 0) alpha += 2 * pi;
        //printf("%.5lf\n",theta);
        //printf("%.5lf %.5lf\n",alpha-theta,alpha+theta);
        FLT lo = alpha - theta;
        FLT hi = alpha + theta;
        if (alpha - theta < -eps) {
            S++;
            lo += 2 * pi;
        }
        e.push_back(event(lo, 1));
        if (hi > 2 * pi + eps) {
            S++;
            hi -= 2 * pi;
        }
        e.push_back(event(hi, -1));
    }
    sort(e.begin(), e.end());
    if (S >= k) return true;
    for (auto &t : e) {
        S += t.second;
        if (S >= k) return true;
    }
    return false;
}

int main() {
    int o = 0;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d",&x,&y);
        if (x == 0 && y == 0) o++;
        else p.emplace_back(x, y);
    }
    if (o >= k) {
        puts("0.000000000");
        return 0;
    }
    k -= o;
    n = p.size();
    //check(2.2360681423);
    //return 0;
    FLT L = 0.00, R = 200010;
    for (int _ = 0; _ < 50; _++) {
        FLT mid = (L + R) / 2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    printf("%.10lf\n",double(R));
}