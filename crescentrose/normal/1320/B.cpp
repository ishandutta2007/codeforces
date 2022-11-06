#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int dis[N];
int n, m;
vector<int>gs[N], gt[N];
int d[N], b[N];
int ansmn, ansmx;
int main() {
    scanf("%d %d", &n,&m);
    for (int i =  1;i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        gs[x].push_back(y);
        gt[y].push_back(x);
    }
    scanf("%d", &d[0]);
    for (int i = 1; i <= d[0]; i ++)
        scanf("%d", &d[i]);
    b[0] = 1, b[1] = d[d[0]];
    dis[d[d[0]]] = 1;
    for (int i = 1; i <= b[0]; i ++)
        for (auto u:gt[b[i]])
            if (!dis[u])
                dis[b[++b[0]] = u] = dis[b[i]] +1;
    for (int i = 1; i < d[0]; i ++) {
        bool sig;
        if (dis[d[i]] != dis[d[i +1]] + 1) {
            ansmx ++;
            ansmn ++;
        } else {
            int sum = 0;
            for (auto u:gs[d[i]])
                sum += (dis[u] + 1 == dis[d[i]]);
            if (sum == 1) {
            } else {
                ansmx ++;
            }
        }
    }
    printf("%d %d\n", ansmn, ansmx);
    return 0;
}