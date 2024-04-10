#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>
using namespace std;
struct Point{int x; int y; int z;};
struct Query{pair<int, int> x; pair<int, int> y; pair<int, int> z; int ind;};
struct Step{pair<int, int> x; pair<int, int> y; int z; int ind; int coeff;};
bool cmp(Point &a, Point &b){
    return (a.z < b.z) ;
}
bool Cmp(Step &a, Step &b){
    return (a.z < b.z);
}
int X;
int rmq[400010];
struct Vertex{int l; int r; int pr; int sz; int value;};
vector<Vertex> decart;
pair<int, int> SP = make_pair(-1, -1);
void update(int vertex){
    if (vertex == -1) return;
    int sz = 1;
    if (decart[vertex].l != -1){
        sz += decart[decart[vertex].l].sz;
    }
    if (decart[vertex].r != -1){
        sz += decart[decart[vertex].r].sz;
    }
    decart[vertex].sz = sz;
}
pair<int, int> split(int father, int number){
    if (father == -1) return SP;
    int l = 1;
    if (decart[father].l != -1){
        l += decart[decart[father].l].sz;
    }
    if (decart[father].value < number){
        pair<int, int> p = split(decart[father].r, number);
        decart[father].r = p.first;
        p.first = father;
        update(father);
        return p;
    }
    pair<int, int> p = split(decart[father].l, number);
    decart[father].l = p.second;
    p.second = father;
    update(father);
    return p;
}
int merg(int first, int second){
    if (first == -1) return second;
    if (second == -1) return first;
    if (decart[first].pr >= decart[second].pr){
        int v = merg(decart[first].r, second);
        decart[first].r = v;
        update(first);
        return first;
    }
    int v = merg(first, decart[second].l);
    decart[second].l = v;
    update(second);
    return second;
}
int get_left(int base, int value){
    if (base == -1) return 0;
    if (decart[base].value >= value) return get_left(decart[base].l, value);
    int sz = 1;
    if (decart[base].l != -1) sz += decart[decart[base].l].sz;
    return sz + get_left(decart[base].r, value);
}
int add(int base, int value){
    pair<int, int> p = split(base, value);
    decart.push_back({-1, -1, rand(), 1, value});
    base = merg(p.first, decart.size() - 1);
    base = merg(base, p.second);
    return base;
}
void change(int i, int l, int r, int ind, int val){
    rmq[i] = add(rmq[i], val);
    if (r-l==1) return;
    int mid = (l+r)/2;
    if (ind < mid) change(2*i+1, l, mid, ind, val);
    else change(2*i+2, mid, r, ind, val);
}
void Change(int x, int y){
    change(0, 0, X+1, x, y);
}
int get(int i, int l, int r, int l1, int r1, pair<int, int> &y){
    if (l1 >= r1) return 0;
    if (l==l1 && r==r1){
        return get_left(rmq[i], y.second + 1) - get_left(rmq[i], y.first);
    }
    int mid = (l+r)/2;
    return get(2*i+1, l, mid, l1, min(r1, mid), y) + get(2*i+2, mid, r, max(l1, mid), r1, y);
}
int Get(pair<int, int> &x, pair<int, int> &y){
    return get(0, 0, X+1, x.first, x.second+1, y);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Y, Z;
    cin >> X >> Y >> Z;
    int INF = 1e7;
    pair<int, int> G = make_pair(INF, -INF);
    pair<int, int> xm = G, ym = G, zm = G;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        xm.first = min(xm.first, x);
        xm.second = max(xm.second, x);
        ym.first = min(ym.first, y);
        ym.second = max(ym.second, y);
        zm.first = min(zm.first, z);
        zm.second = max(zm.second, z);
    }
    vector<Point> p;
    for (int i=0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        bool abl = true;
        if (!(x >= xm.first && x <= xm.second)){
            abl = false;
        }
        if (!(y >= ym.first && y <= ym.second)){
            abl = false;
        }
        if (!(z >= zm.first && z <= zm.second)){
            abl = false;
        }
        if (abl){
            cout << "INCORRECT";
            return 0;
        }
        p.push_back({x, y, z});
    }
    cout << "CORRECT" << "\n";
    vector<Query> d;
    vector<bool> know(k);
    vector<int> pts(k);
    fill(pts.begin(), pts.end(), 0);
    for (int i=0; i < k; i++){
        int x, y, z;
        cin >> x >> y >> z;
        pair<int, int> xx = xm, yy = ym, zz=zm;
        xx.first = min(xx.first, x);
        xx.second = max(xx.second, x);
        yy.first = min(yy.first, y);
        yy.second = max(yy.second, y);
        zz.first = min(zz.first, z);
        zz.second = max(zz.second, z);
        if (xx==xm && yy==ym && zz==zm) know[i] = true;
        else{
            know[i] = false;
            d.push_back({xx, yy, zz, i});
        }
    }
    sort(p.begin(), p.end(), cmp);
    vector<Step> r;
    for (int i=0; i < d.size(); i++){
        r.push_back({d[i].x, d[i].y, d[i].z.first - 1, d[i].ind, -1});
        r.push_back({d[i].x, d[i].y, d[i].z.second, d[i].ind, 1});
    }
    sort(r.begin(), r.end(), Cmp);
    for (int i=0; i < 4*(X+1); i++) rmq[i] = -1;
    int u = 0;
    for (int i=0; i < p.size(); i++){
        while (u < r.size() && r[u].z < p[i].z){
            int res = Get(r[u].x, r[u].y);
            int ind = r[u].ind, cf = r[u].coeff;
            pts[ind] += res*cf;
            u++;
        }
        Change(p[i].x, p[i].y);
    }
    while (u < r.size()){
        int res = Get(r[u].x, r[u].y);
        int ind = r[u].ind, cf = r[u].coeff;
        pts[ind] += res*cf;
        u++;
    }
    for (int i=0; i < k; i++){
        if (know[i]){
            cout << "OPEN" << "\n";
        }
        else{
            if (pts[i] == 0) cout << "UNKNOWN" << "\n";
            else cout << "CLOSED" << "\n";
        }
    }
    return 0;
}