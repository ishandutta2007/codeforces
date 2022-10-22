#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

#define val(x, y) ((x) * 1100 + (y))

int n, m, g, r;
int dist[11000 * 1100];
int d[11000];

int main(){
    fill(dist, dist + 11000 * 1100, INF);
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i++)scanf("%d", &d[i]);
    scanf("%d%d", &g, &r);
    sort(d, d + m);
    dist[val(0,0)] = 0;
    deque<int> q;
    q.push_front(val(0,0));
    int ans = INF;
    while(!q.empty()){
        int v = q.front();q.pop_front();
        int i = v / 1100, j = v % 1100;
//        cout << i << " " << j << " " << dist[v] << endl;
        if(i == m-1){
            ans = min(ans, dist[v] * (g+r) + j);
            continue;
        }
        if(i < m-1){
            int x = d[i+1] - d[i];
            if(j + x <= g){
                int nxt = val(i+1, j+x);
                if(dist[nxt] != INF)continue;
                dist[nxt] = dist[v];
                q.push_front(nxt);
            }
        }
        if(i > 0){
            int x = d[i] - d[i-1];
            if(j + x <= g){
                int nxt = val(i-1, j+x);
                if(dist[nxt] != INF)continue;
                dist[nxt] = dist[v];
                q.push_front(nxt);
            }
        }
        if(j == g){
            int nxt = val(i, 0);
            if(dist[nxt] != INF)continue;
            dist[nxt] = dist[v] + 1;
            q.push_back(nxt);
        }
    }
    if(ans == INF)ans = -1;
    printf("%d\n", ans);
    return 0;
}