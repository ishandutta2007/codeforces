#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii> > pq;

int n, h[1 << 20];
int s[1 << 20];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
        pq.push(make_pair(h[i], i));
    }
    pq.push(make_pair(1, 0));
    pq.push(make_pair(1, n - 1));
    memset(s, 63, sizeof(s));

    while (pq.size()) {
        pii p = pq.top();
        pq.pop();
        if (p.first < s[p.second]) {
            s[p.second] = p.first;
            if (p.second + 1 < n) {
                pq.push(make_pair(p.first + 1, p.second + 1));
            }
            if (p.second - 1 >= 0) {
                pq.push(make_pair(p.first + 1, p.second - 1));
            }
        }
    }

    int mx = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] > mx) {
            mx = s[i];
        }
    }
    printf("%d\n", mx);
    return 0;
}