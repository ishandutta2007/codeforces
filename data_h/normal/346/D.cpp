#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

const int N = 1111111;
const int inf = 1000000000;

int f[N], visit[N], dgr[N];
int n, m;
vector<int> e[N];
int s, t;
deque<pair<int, int> > q;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[b].push_back(a);
        dgr[a]++;
    }
    for(int i = 1; i <= n; i++)
        f[i] = inf;
    scanf("%d %d", &s, &t);
    q.push_back(make_pair(t, 0));
    while(q.size()) {
        int x = q.front().first, d = q.front().second;
        q.pop_front();
        if (f[x] <= d)
            continue;
        f[x] = d;
        for(int i = 0; i < e[x].size(); i++) {
            int y = e[x][i];
            if (--dgr[y] == 0) {
                q.push_front(make_pair(y, f[x]));
            } 
        }
        for(int i = 0; i < e[x].size(); i++) {
            int y = e[x][i];
            q.push_back(make_pair(y, f[x] + 1));
        }
    }
    if (f[s] >= inf / 2)
        printf("-1\n");
    else
        printf("%d\n", f[s]);
    return 0;
}