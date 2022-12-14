#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> tr;
vector<pii> ot;

int a[1 << 20], b[1 << 20];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int w, t;
        scanf("%d %d", &w, &t);
        if (t) {
            tr.push_back(make_pair(w, i));
        } else {
            ot.push_back(make_pair(w, i));
        }
    }
    sort(tr.begin(), tr.end());
    sort(ot.begin(), ot.end());

    for (int i = 0; i < (int) tr.size(); ++i) {
        a[tr[i].second] = i + 1;
        b[tr[i].second] = i + 2;
    }

    int A = 3;
    int B = 1;
    int k = 0;
    for (int i = 0; i < (int) ot.size(); ++i) {
        if (A > n || ot[i].first < tr[A - 2].first) {
            printf("-1\n");
            return 0;
        }
        a[ot[i].second] = A;
        b[ot[i].second] = B;
        B++;
        if (A == B + 1) {
            ++A;
            B = 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        printf("%d %d\n", a[i], b[i]);
    }

    return 0;
}