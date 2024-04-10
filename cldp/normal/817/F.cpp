#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 5000010;
const int MAXQ = 100010;
//const LL INF = 8;
const LL INF = 10000000;
const double PI = acos(-1.0);


struct node {
    int L, R;
    // 0 nothing, 1 add, 2 del, 3 rev
    int mark; 
    LL cnt;
};

int M;
node X[MAXN];


void clear(int t, LL a, LL b) {
    if (a == b) {
        X[t].mark = 0;
        return ;
    }

    if (M == MAXN) while (1) ;
    if (X[t].L == 0) X[t].L = ++M;
    if (X[t].R == 0) X[t].R = ++M;
    if (X[t].mark == 0) return ;

    LL mid = (a + b) / 2;
    if (X[t].mark == 1) {
        X[X[t].L].mark = X[X[t].R].mark = 1;
        X[X[t].L].cnt = mid - a + 1;
        X[X[t].R].cnt = b - (mid + 1) + 1;
    } else 
    if (X[t].mark == 2) {
        X[X[t].L].mark = X[X[t].R].mark = 2;
        X[X[t].L].cnt = X[X[t].R].cnt = 0;
    } else {
        if (X[X[t].L].mark == 1 || X[X[t].L].mark == 2) clear(X[t].L, a, mid);
        if (X[X[t].L].mark == 0) {
            X[X[t].L].mark = 3;
            X[X[t].L].cnt = mid - a + 1 - X[X[t].L].cnt;
        } else {
            X[X[t].L].mark = 0;
            X[X[t].L].cnt = mid - a + 1 - X[X[t].L].cnt;
        }
        if (X[X[t].R].mark == 1 || X[X[t].R].mark == 2) clear(X[t].R, mid + 1, b);
        if (X[X[t].R].mark == 0) {
            X[X[t].R].mark = 3;
            X[X[t].R].cnt = b - (mid + 1) + 1 - X[X[t].R].cnt;
        } else {
            X[X[t].R].mark = 0;
            X[X[t].R].cnt = b - (mid + 1) + 1 - X[X[t].R].cnt;
        }
    }
    X[t].mark = 0;
}

void add(int t, LL a, LL b, LL l, LL r) {
  //  cout << t << " " << a << " "<< b<< " " << l << " " << r << endl;
    if (a <= l && r <= b) {
        X[t].mark = 1;
        X[t].cnt = r - l + 1;
        return ;
    }
    clear(t, l, r);
    LL mid = (l + r) / 2;
    if (a <= mid && b >= l) add(X[t].L, a, b, l, mid);
    if (a <= r && b >= mid + 1) add(X[t].R, a, b, mid + 1, r);
  //  cout << t << " " << X[X[t].L].cnt << " " << X[X[t].R].cnt << endl;
    X[t].cnt = X[X[t].L].cnt + X[X[t].R].cnt; 
}


void del(int t, LL a, LL b, LL l, LL r) {
    if (a <= l && r <= b) {
        X[t].mark = 2;
        X[t].cnt = 0;
        return ;
    }
    clear(t, l, r);
    LL mid = (l + r) / 2;
    if (a <= mid && b >= l) del(X[t].L, a, b, l, mid);
    if (a <= r && b >= mid + 1) del(X[t].R, a, b, mid + 1, r);
    X[t].cnt = X[X[t].L].cnt + X[X[t].R].cnt; 
}

void rev(int t, LL a, LL b, LL l, LL r) {
  //  cout << t << " " << a << " " << b << " " << " " << l << " " << r << endl;
    clear(t, l, r);
    if (a <= l && r <= b) {
        X[t].mark = 3;
        X[t].cnt = r - l + 1 - X[t].cnt;
        return ;
    }
    LL mid = (l + r) / 2;
    if (a <= mid && b >= l) rev(X[t].L, a, b, l, mid);
    if (a <= r && b >= mid + 1) rev(X[t].R, a, b, mid + 1, r);
    X[t].cnt = X[X[t].L].cnt + X[X[t].R].cnt; 
}

LL query(int t, LL l, LL r) {
    if (l == r) return l;
    clear(t, l, r);
    if (X[t].cnt == r - l + 1) return INF + 1;
    LL mid = (l + r) / 2;
    if (X[X[t].L].cnt != mid - l + 1) return query(X[t].L, l, mid);
    return query(X[t].R, mid + 1, r);
}

map<LL, int> SS;
LL A[MAXQ], B[MAXQ], C[MAXQ];
vector<LL> SB;

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i] >> C[i];
        SS[B[i]] = SS[B[i] - 1] = SS[B[i] + 1] = 0;
        SS[C[i]] = SS[C[i] - 1] = SS[C[i] + 1] = 0;
    }
    SS[1] = 0;

    SB.push_back(0);
    int MMM = 0;
    for (auto iter = SS.begin(); iter != SS.end(); ++iter) {
        if (iter->first == 0) continue;
        iter->second = ++MMM;
        SB.push_back(iter->first);
       // cout << iter->first << " " << iter->second << endl;
    }

    for (int i = 0; i < N; ++i) {
      //  cout << SS[B[i]] << " " << SS[C[i]] << endl;
        if (A[i] == 1) {
            add(0, SS[B[i]], SS[C[i]], 1, INF);
        } else
        if (A[i] == 2) {
            del(0, SS[B[i]], SS[C[i]], 1, INF);
        } else {
            rev(0, SS[B[i]], SS[C[i]], 1, INF);
        }
      //  cout << query(0, 1, INF) << endl;
      //  cout << X[0].cnt << endl;
        cout << SB[query(0, 1, INF)] << endl;
   // for (int j = 0; j <= M; ++j) cout << j << " " << X[j].L << " " << X[j].R << " " << X[j].cnt << " " << X[j].mark << endl;
    }

    return 0;
}