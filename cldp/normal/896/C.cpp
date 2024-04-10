#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;

struct node {
    int a, b;
    long long x;

    node () {}
    node(int _a, int _b, long long _x): a(_a), b(_b), x(_x) {}

    bool operator < (const node &B) const {
        return a < B.a;
    }
};

struct snum {
    long long x;
    int t;

    snum() {}
    snum(long long _x, int _t): x(_x), t(_t) {}

    bool operator < (const snum &B) const {
        return x < B.x;
    }
};

int N, M, S, V;
set<node> X;

long long qp(long long a, int x, int y) {
    if (x == 0) return 1;
    if (x == 1) return a % y;
    long long ans = qp(a * a % y, x / 2, y);
    if (x & 1) return ans * a % y;
    return ans;
}

int rnd() {
    int ans = S;
    S = (1LL * S * 7 + 13) % INF;
    return ans;
}

void printt() {
    for (set<node>::iterator iter = X.begin(); iter != X.end(); ++iter) {
        cout << iter->a << " " << iter->b << " " << iter->x << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> S >> V;
    for (int i = 1; i <= N; ++i) X.insert(node(i, i, rnd() % V + 1));
    for (int i = 1; i <= M; ++i) {
        int op = rnd() % 4 + 1;
        int l = rnd() % N + 1;
        int r = rnd() % N + 1;
        if (l > r) swap(l, r);

        int x, y;
        if (op == 3) {
            x = rnd() % (r - l + 1) + 1;
        } else {
            x = rnd() % V + 1;
        }
        if (op == 4) {
            y = rnd() % V + 1;
        }

        if (op == 1) {
            set<node>::iterator it1 = X.lower_bound(node(l, l, 0));
            if (it1->a != l) --it1;
            node temp = *it1;

            set<node>::iterator it2 = it1;
            ++it2;
            X.erase(it1);

            if (temp.a < l) X.insert(node(temp.a, l - 1, temp.x));
            if (r <= temp.b) {
                if (r < temp.b) X.insert(node(r + 1, temp.b, temp.x));
                X.insert(node(l, r, temp.x + x));
                continue;
            }

            X.insert(node(l, temp.b, temp.x + x));

            while (it2 != X.end() && it2->b < r) {
                it1 = it2;
                ++it2;
                node temp = *it1;
                X.erase(it1);
                X.insert(node(temp.a, temp.b, temp.x + x));
            }

            if (it2 != X.end() && r < it2->b) {
                X.insert(node(r + 1, it2->b, it2->x));
            } 

            temp = *it2;
            X.erase(it2);            
            X.insert(node(temp.a, r, temp.x + x));


        } 
        if (op == 2) {
            set<node>::iterator it1 = X.lower_bound(node(l, l, 0));
            if (it1->a != l) --it1;
            node temp = *it1;

            set<node>::iterator it2 = it1;
            ++it2;
            X.erase(it1);

            if (temp.a < l) X.insert(node(temp.a, l - 1, temp.x));
            if (r <= temp.b) {
                if (r < temp.b) X.insert(node(r + 1, temp.b, temp.x));
                X.insert(node(l, r, x));
                continue;
            }

            while (it2 != X.end() && it2->b < r) {
                it1 = it2;
                ++it2;
                X.erase(it1);
            }

            if (it2 != X.end() && r < it2->b) {
                X.insert(node(r + 1, it2->b, it2->x));
            } 
            X.erase(it2);

            X.insert(node(l, r, x));
        }
        if (op == 3) {
            vector<snum> Y;

            set<node>::iterator it1 = X.lower_bound(node(l, l, 0));
            if (it1->a != l) --it1;

            while (it1 != X.end()) {
                if (r < it1->a) break;
                int a = max(l, it1->a);
                int b = min(r, it1->b);
                Y.push_back(snum(it1->x, b - a + 1));
                ++it1;
            }
            sort(Y.begin(), Y.end());
            for (int i = 0; i < Y.size(); ++i) {
                if (x <= Y[i].t) {
                    cout << Y[i].x << endl;
                    break;
                }
                x -= Y[i].t;
            }
        }
        if (op == 4) {
            set<node>::iterator it1 = X.lower_bound(node(l, l, 0));
            if (it1->a != l) --it1;

            long long ans = 0;
            while (it1 != X.end()) {
                if (r < it1->a) break;
                int a = max(l, it1->a);
                int b = min(r, it1->b);
                ans = (ans + qp(it1->x % y, x, y) * (b - a + 1)) % y;
                ++it1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}