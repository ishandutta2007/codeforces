#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);
const int nn = 1 << 20;

typedef pair<double, double> pdd;

double cs[360], sn[360];

double X[nn], Y[nn];
int A[nn];
int l[nn];

pdd get(int id) {
    double x = X[id] * cs[A[id]] - Y[id] * sn[A[id]];
    double y = X[id] * sn[A[id]] + Y[id] * cs[A[id]];
    return pdd(x, y);
}

void addA(int& a, int d) {
    a += d;
    if (a >= 360) a -= 360;
}

void inc(int id, int L, int R, int p, int val) {
    if (L + 1 == R) {
        l[id] += val;
        X[id] = l[id];
    } else {
        int M = (L + R) / 2;
        
        addA(A[id * 2], A[id]);
        addA(A[id * 2 + 1], A[id]);
        A[id] = 0;
        
        if (p < M)
            inc(id * 2, L, M, p, val);
        else
            inc(id * 2 + 1, M, R, p, val);
        
        pdd pl = get(id * 2);
        pdd pr = get(id * 2 + 1);
        
        X[id] = pl.first + pr.first;
        Y[id] = pl.second + pr.second;
    }
}

void rotate(int id, int L, int R, int left, int val) {
    if (left <= L) {
       addA(A[id], val);
    } else {
        int M = (L + R) / 2;
                
        rotate(id * 2 + 1, M, R, left, val);
        
        if (left < M)
            rotate(id * 2, L, M, left, val);
        
        pdd pl = get(id * 2);
        pdd pr = get(id * 2 + 1);
        
        X[id] = pl.first + pr.first;
        Y[id] = pl.second + pr.second;
        
//        cerr << "L " << pl.first << ' ' << pl.second << endl;
//        cerr << "R " << pr.first << ' ' << pr.second << endl;
//       cerr << id << ' ' << X[id] << ' ' << Y[id] << endl;
    }
}

void inc(int p, int L) {
    inc(1, 0, nn / 2, p, L);
}

void rotate(int p, int a) {
    rotate(1, 0, nn / 2, p, a);
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    for (int i = 0; i < 360; ++i) {
        cs[i] = cos(i * pi / 180.);
        sn[i] = sin(i * pi / 180.);
    }
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) 
        inc(i, 1);
    
    for (int i = 0; i < m; ++i) {
        int z, id, val;
        cin >> z >> id >> val;
        if (z == 1) {
            inc(id - 1, val);
        } else {
            rotate(id - 1, 360 - val);
        }
        
        cout.precision(15);
        pdd p = get(1);
        cout << fixed << p.first << ' ' << p.second << '\n';
    }
    
    return 0;
}