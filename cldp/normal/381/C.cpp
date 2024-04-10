#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1100;
const int INF = 1000000000;

struct node {
    int t;
    long long a, b, c;
};

int n, m;
vector<node> x;
long long y[100010];

long long find(long long a) {
    long long l = 0, r = m;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (x[mid].c <= a) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}


int main() {
    cin >> m;
    long long begin = 1;
    for (int i = 0; i < m; ++i) {
        node p;
        cin >> p.t;
        p.c = begin;
        if (p.t == 1) {
            cin >> p.a; 
        } else {
            cin >> p.a >> p.b;
        }
        
        x.push_back(p);
        if (begin > 100000) {
            if (p.t == 1) ++begin; else begin += p.a * p.b;
            continue;
        }
        if (p.t == 1) {
            y[begin] = p.a;
            ++begin;
        } else {
            long long temp = begin;
            for (int i = 0; i < p.b; ++i) {
                for (int j = 1; j <= p.a; ++j) {
                    y[temp] = y[j];
                    ++temp;
                    if (temp > 100000) break;
                }
                if (temp > 100000) break;
            }
            begin += p.a * p.b;
        }
    }
    node pp;
    pp.c = begin;
    x.push_back(pp);
    //for (int i = 0; i < m; ++i) cout << i << " " << x[i].c << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a <= 100000) {
            cout << y[a] << endl;
            continue;
        } else {
            long long p = find(a);
            //cout << "p " << p << endl;
            if (x[p].t == 1) {
                cout << x[p].a << endl;
            } else {
                cout << y[(a - x[p].c) % x[p].a + 1] << endl;
            }
        }
    }
    

    return 0;
}