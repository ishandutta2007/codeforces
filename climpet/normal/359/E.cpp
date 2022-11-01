#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


int n, xs, ys;
char field[512][512];
vint G[512 * 512], G2[512 * 512];
int from[512 * 512];
bool visit[512 * 512];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int dif[] = {-512, 1, 512, 1};
const char *fmt = "URDL";


void bfs(){
    int v = ys * 512 + xs;
    from[v] = 4;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i = 0; i < G[v].size(); ++i){
            int d = G[v][i];
            int y = (v >> 9) + dy[d];
            int x = (v & 511) + dx[d];
            int u = y * 512 + x;
            if(field[y][x] != 2 && from[u] == -1){
                from[u] = (d + 2) & 3;
                q.push(u);
            }
        }
    }
}


void traverse(int y, int x){
    int u = y * 512 + x;
    while(!visit[u]){
        visit[u] = true;
        y += dy[from[u]];
        x += dx[from[u]];
        int v = y * 512 + x;

        G2[v].push_back((from[u] + 2) & 3);
        u = v;
    }
}


void dfs(int y, int x){
    if(field[y][x] == 0){
        putchar('1');
    }

    int v = y * 512 + x;
    for(int i = 0; i < G2[v].size(); ++i){
        int d = G2[v][i];
        putchar(fmt[d]);
        dfs(y + dy[d], x + dx[d]);
        putchar(fmt[(d + 2) & 3]);
    }
    
    putchar('2');
}


int main(){
    int t;
    scanf("%d%d%d", &n, &ys, &xs);
    memset(field, 2, sizeof field);
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
        scanf("%d", &t);
        field[i][j] = t;
    }
    
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
        if(field[i][j] == 1){
            for(int d = 0; d < 4; ++d){
                int y = i + dy[d], x = j + dx[d];
                while(field[y][x] != 2){
                    G[y * 512 + x].push_back((d + 2) & 3);
                    if(field[y][x] == 1){ break; }
                    y += dy[d];
                    x += dx[d];
                }
            }
        }
    }

    memset(from, -1, sizeof from);
    bfs();

    visit[ys * 512 + xs] = true;

    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
        if(field[i][j] == 1){
            if(from[i * 512 + j] == -1){
                puts("NO");
                return 0;
            }
            
            traverse(i, j);
        }
    }

    puts("YES");
    dfs(ys, xs);
    puts("");
}