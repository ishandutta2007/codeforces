#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define szz(x) (int)(x).size()
#define Fi first
#define Se second

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int IT_MAX = 1 << 17;

const int MX = 1000005;

pii operator-(pii a, pii b) { return pii(a.Fi - b.Fi, a.Se - b.Se); }
ll operator/(pii a, pii b) { return (ll)a.Fi * b.Se - (ll)a.Se * b.Fi; }

struct point {
    point() {}
    point(pii p, int v) : p(p), v(v) {}
    pii p;
    int v;
};

int N;
vector <point> V;
int A[30030];
int ans[30030];

void Do(vector <point> &X) {
    if(szz(X) == 0) return;
    if(szz(X) == 2) {
        if(X[0].v > 0) ans[X[0].v] = -X[1].v;
        else ans[X[1].v] = -X[0].v;
        return;
    }
    int a = rand() % 10000 + 1;
    int b = rand() % 20000 - 10000;
    int fv = 0, m = szz(X);
    for(int i=1;i<m;i++) {
        ll vi = (ll)(X[i].p.Fi - X[fv].p.Fi) * a + (ll)(X[i].p.Se - X[fv].p.Se) * b;
        if(vi < 0) fv = i;
    }
    swap(X[0], X[fv]);
    for(int i=m-1;i>=0;i--) X[i].p = X[i].p - X[0].p;
    sort(X.begin() + 1, X.end(), [](point &a, point &b) {
        return a.p / b.p > 0;
    });
    int cf = (X[0].v > 0 ? 1 : -1);
    A[0] = cf;
    int tar = m / 2, f = -1;
    for(int i=1;i<m;i++) {
        int val = 0;
        if(X[i].v > 0) val = 1;
        else val = -1;
        A[i] = A[i-1] + val;
        if(A[i] == 0 && val != cf) {
            if(f == -1 || abs(tar-f) > abs(tar-i)) f = i;
        }
    }
    if(X[0].v > 0) ans[X[0].v] = -X[f].v;
    else ans[X[f].v] = -X[0].v;

    vector <point> NX;
    if(f > tar) {
        for(int i=m-1;i>f;i--) NX.pb(X[i]);
        for(int i=0;i<f-1;i++) X[i] = X[i+1];
        while(szz(X) > f-1) X.pop_back();
        Do(X);
        Do(NX);
    }
    else {
        for(int i=1;i<f;i++) NX.pb(X[i]);
        for(int i=0;i<m-f-1;i++) X[i] = X[i + f + 1];
        while(szz(X) > m-f-1) X.pop_back();
        Do(X);
        Do(NX);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        int x, y; scanf("%d%d", &x, &y);
        V.emplace_back(pii(x, y), i);
    }
    for(int i=1;i<=N;i++) {
        int x, y; scanf("%d%d", &x, &y);
        V.emplace_back(pii(x, y), -i);
    }
    Do(V);
    for(int i=1;i<=N;i++) printf("%d\n", ans[i]);
    return 0;
}