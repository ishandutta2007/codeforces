#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <assert.h>
#include <cmath>
using namespace std;

typedef double db;
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

const double EPS = 1e-9;
const double PI = acos(-1);

const int MX = 100005;

pdd operator+(pdd l, pdd r){ return pdd(l.first + r.first, l.second + r.second);  }
pdd operator-(pdd l, pdd r){ return pdd(l.first - r.first, l.second - r.second);  }
double operator*(pdd a, pdd b) { return a.Fi * b.Fi + a.Se * b.Se; }
pdd operator*(pdd l, double r){ return pdd(l.first * r, l.second * r);  }
double operator/(pdd l, pdd r){ return l.first*r.second - l.second*r.first;  }
pdd r90(pdd c){ return pdd(-c.second, c.first); }
double size(pdd c){ return hypot(c.first, c.second); }
double sq(double x){ return x*x;}
double size2(pdd c){ return sq(c.first) + sq(c.second); }
pdd unit(double a){ return pdd(cos(a), sin(a)); }
pdd rotate(pdd v, double a){ return unit(a) * v.first + unit(a + PI/2) * v.second; }

int intersect(pdd a, pdd b, pdd u, pdd v, pdd &des){
    if(abs(u/v) < EPS) return 0;
    des = pdd(((a-u)/v)/(v/b), ((a-u)/b)/(v/b));
    return 1;
}

struct circle{
    circle(pdd O, double r):O(O), r(r){}
    circle(){}
    pdd O;
    double r;
};

int get_circle(pdd p0, pdd p1, pdd p2, circle &des){
    pdd a = (p0+p1) * 0.5, b = r90(p0-p1);
    pdd u = (p0+p2) * 0.5, v = r90(p0-p2), R;
    if( !intersect(a, b, u, v, R) ) return 0;
    des = circle(a+b*R.first, size(a+b*R.first - p0));
    return 1;
}

struct node{
    node(int a, int b, int c, circle X):a(a), b(b), c(c), X(X){}
    int a, b, c;
    circle X;
};

node make_circle(vector<int> Q, pdd D[MX]){
    if( Q.size() == 0 ) return node(-1, -1, -1, circle(pdd(0, 0), 0));
    if( Q.size() == 1 ) return node(Q[0], -1, -1, circle(D[Q[0]], 0));
    circle res;
    for(int i = 0; i < Q.size(); i++){
        swap(Q.back(), Q[i]);
        res = circle((D[Q[0]]+D[Q[1]]) * 0.5, size(D[Q[0]]-D[Q[1]])/2);
        bool ch = 1;
        for(int c : Q){
            if( size2(D[c]-res.O) > sq(res.r) + 1e-6) ch = 0;
        }
        if( ch ) return node(Q[0], Q[1], -1, res);
        swap(Q.back(), Q[i]);
    }
    get_circle(D[Q[0]], D[Q[1]], D[Q[2]], res);
    return node(Q[0], Q[1], Q[2], res);
}

node smallest_circle(vector<int> &P, vector<int> &Q, int N, pdd D[MX])
{
    node c = make_circle(Q, D);
    if( N == 0 || Q.size() >= 3 ) return c;
    for(int i = 0; i < N; i++){
        if( size2(c.X.O - D[P[i]]) > sq(c.X.r) ){
            Q.push_back(P[i]);
            c = smallest_circle(P, Q, i, D);
            Q.pop_back();
        }
    }
    return c;
}

int counter = 0;
void get_enc(vector<int> L, vector<int> X, vector<node> &ans, pdd D[MX], double prob = 1){
    if(prob < 1e-4) return;
    counter++;
    vector<int> P, Q;
    random_shuffle(L.begin(), L.end());
    for(int c : X) P.push_back(c);
    for(int c : L) P.push_back(c);
    node x = smallest_circle(P, Q, L.size(), D);
    ans.push_back(x);
    vector<int> t1;
    auto is_in = [](vector<int> &X, int x){
        for(int c : X) if(c == x) return true;
        return false;
    };
    if(!is_in(X, x.a)) t1.push_back(x.a);
    if(!is_in(X, x.b)) t1.push_back(x.b);
    if(!is_in(X, x.c)) t1.push_back(x.c);

    for(int c : t1){
        for(int j = 0; j < L.size(); j++) if(L[j] == c) L.erase(L.begin()+j);
        get_enc(L, X, ans, D, prob / 3);
        prob = prob * 2 / 3;
        X.push_back(c);
    }
}

pdd D1[MX], D2[MX];
int N, N1, N2;
map <pii, int> Mx;

void check(pdd O1, pdd O2, double a)
{
    auto move = [&](pdd c){
        return rotate(c - O1, a) + O2;
    };
    counter++;
    int corr = 0;
    vector <pii> ansv;
    for(int i=1;i<=N1;i++) {
        pdd ex = move(D1[i]);

        int tx = (int)(ex.first * 100 + 0.5);
        int ty = (int)(ex.second * 100 + 0.5);
        int f = 0;
        for(int dx=-1;dx<=1;dx++) for(int dy=-1;dy<=1;dy++) if(f == 0) {
            if(Mx.find(pii(tx + dx, ty + dy)) != Mx.end()) {
                int idx = Mx[pii(tx + dx, ty + dy)];
                ansv.emplace_back(i, idx);
                f = 1;
            }
        }
        corr += f;
        if(i > 100 && ((double)corr / i) * N1 < N * 0.5) break;
    }
    if(szz(ansv) > 0.91 * N) {
        int chkA[MX] = {}, chkB[MX] = {};
        for(pii e : ansv) chkA[e.Fi] = chkB[e.Se] = 1;
        int ia = 1, ib = 1;
        while(szz(ansv) < N) {
            while(chkA[ia] == 1) ++ia;
            while(chkB[ib] == 1) ++ib;
            ansv.pb(pii(ia, ib));
            ++ia; ++ib;
        }
        for(pii e : ansv) printf("%d %d\n", e.Fi, e.Se);
        exit(0);
    }
}

int main()
{
//    freopen("A.out","r",stdin);
    scanf("%d", &N);
    scanf("%d", &N1);
//    printf("%d %d\n", N, N1);
    for(int i = 1; i <= N1; i++) scanf("%lf%lf", &D1[i].first, &D1[i].second);
    scanf("%d", &N2);
    for(int i = 1; i <= N2; i++) scanf("%lf%lf", &D2[i].first, &D2[i].second);
    for(int i=1;i<=N2;i++) {
        int tx = (int)(D2[i].first * 100 + 0.5);
        int ty = (int)(D2[i].second * 100 + 0.5);
        Mx[pii(tx, ty)] = i;
    }

    vector<int> t1, t2;
    vector<node> A1, A2;
    for(int i = 1; i <= N1; i++) t1.push_back(i);
    get_enc(t1, t2, A1, D1);

    t1.clear();
    for(int i = 1; i <= N2; i++) t1.push_back(i);
    get_enc(t1, t2, A2, D2);
 //   printf("%d\n", counter); counter = 0;

    for(node a1 : A1){
        for(node a2 : A2){
            if(fabs(a1.X.r - a2.X.r) > 0.1 ) continue;
            pdd P1[] = {D1[a1.a], D1[a1.b], D1[a1.c]};
            pdd P2[] = {D2[a2.a], D2[a2.b], D2[a2.c]};

            for(pdd &c : P1) c = c - a1.X.O;
            for(pdd &c : P2) c = c - a2.X.O;

            int O[3] = {0, 1, 2};
            do{
                int ch = 1;
                double t = atan2(P1[0] / P2[O[0]], P1[0] * P2[O[0]]);
                for(int i = 1; i < 3; i++){
                    double u = atan2(P1[i] / P2[O[i]], P1[i] * P2[O[i]]);
                    if(fabs(t-u) < EPS) ch = 0;
                }
                check(a1.X.O, a2.X.O, t);
            }while(next_permutation(O, O+3));
        }
    }
  //  printf("%d\n", counter); counter = 0;
}