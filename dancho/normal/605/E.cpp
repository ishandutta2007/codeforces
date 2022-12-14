#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const double eps = 1e-7;

int n;
double pr[1024][1024];

bool us[1024];
double sm[1024], de[1024];
double s[1024];

typedef pair<double, int> pdi;

priority_queue<pdi, vector<pdi>, greater<pdi> > pq;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int p;
            scanf("%d", &p);
            pr[i][j] = (double) p / 100.0;
        }
        sm[i] = 0;
        de[i] = 1;
        s[i] = 1e100;
    }

    memset(us, 0, sizeof(us));
    s[n - 1] = 0;
    pq.push(make_pair(s[n - 1], n - 1));
    while (pq.size()) {
        pdi p = pq.top();
        pq.pop();
        if (us[p.second]) {
            continue;
        }
        us[p.second] = 1;
        if (p.second == 0) {
            break;
        }
        int v = p.second;
        for (int i = 0; i < n; ++i) {
            if (!us[i]) {
                sm[i] += de[i] * pr[i][v] * (1. + p.first);
                de[i] *= (1. - pr[i][v]);
                double next = (double) (sm[i] + de[i]) / (1. - de[i]);
                if (next + eps < s[i]) {
                    s[i] = next;
                    pq.push(make_pair(s[i], i));
                }
            }
        }
    }
    printf("%.10lf\n", s[0]);
    return 0;
}