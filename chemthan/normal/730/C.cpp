#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>
#include <cfloat>
#include <iomanip>
#include <stack>
#include <bitset>


using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ft(a) __typeof((a).begin())
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define bitcount(n) __builtin_popcountll(n)
#define pii pair<int, int>


typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int N = 5000 + 7;
const int M = 1000 + 3;
const int inf = 1e9 + 7;
const long long linf = 1ll * inf * (inf - 1);
const double pi = acos(-1);
const double eps = 1e-6;
const bool multipleTest = false;


vi adj[N];
vii store[N];
int n, m;
int qu[N], top, bot;
int d[N];
int k;
//ii can[N];
int cnt[2000000];
bool check[N];
vi vp;



vii list[N];




bool bfs(int root, int tm, ll amount, ll money) {
    
//    k = 0;
    for(int x = 0; x <= tm; ++x) {
        for(int j = 0; j < list[x].size(); ++j)
        	cnt[list[x][j].fi] += list[x][j].se;
//            can[k++] = list[x][j];
    }

//    sort(can, can + k);
    
    for(int j = 0; j < vp.size() && money >= 0 && amount > 0; ++j) {
    	int i = vp[j];
        if (amount >= cnt[i]) {
            amount -= cnt[i];
            money -= 1ll * i * cnt[i];
        } else {
            money -= 1ll * amount * i;
            amount = 0;
            break;
        }
    }
    
    for(int x = 0; x <= tm; ++x) {
        for(int j = 0; j < list[x].size(); ++j)
        	cnt[list[x][j].fi] -= list[x][j].se;
//            can[k++] = list[x][j];
    }
    
    return amount == 0 && money >= 0;
}

void checkBFS(int root) {
    top = bot = 0;
    top = bot = 0;
    qu[bot++] = root;
    
    for(int i = 1; i <= n; ++i) d[i] = -1;
    d[root] = 0;
    
    for(int i = 0; i < n; ++i) list[i].clear();
    
    while (top < bot) {
        int u = qu[top++];
        
        for(int j = 0; j < store[u].size(); ++j) {
            list[d[u]].push_back(store[u][j]);
        }
        
        for(int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j];
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                qu[bot++] = v;
                
            }
        }
    }

}

void solve() {
//	freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int w;
    cin >> w;
    for(int i = 0; i < w; ++i) {
        int c, k, p;
        scanf("%d%d%d", &c, &k, &p);
        store[c].push_back(mk(p, k));
        vp.pb(p);
    }
    sort(vp.begin(), vp.end());
    vp.erase(unique(vp.begin(), vp.end()), vp.end());
    
    
    int q;
    cin >> q;
    while (q-- > 0) {
        int amount, city, money;
        scanf("%d%d%d", &city, &amount, &money);
        checkBFS(city);
        
        int lo = 0, hi = n - 1, res = -1;
        while (lo <= hi) {
            int g = (lo + hi) >> 1;
            if (bfs(city, g, amount, money)) {
                res = g;
                hi = g - 1;
            } else lo = g + 1;
        }
        printf("%d\n", res);
    }
}

void createTest() {
    freopen("in.txt", "w", stdout);
    cout << 1 << "\n";
    cout << 100000 << " " << 100000 << "\n";
    for(int i = 1; i <= 100000; ++i) {
        int u = rand();
        int v = rand();
        if (u > v) swap(u, v); printf("%d %d\n", u, v);
    }
    for(int i = 1; i <= 100000; ++i) {
        int u = rand();
        int v = rand();
        if (u > v) swap(u, v); printf("%d %d\n", u, v);
    }
}



int main() {
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    clock_t t1 = clock();
//#endif
    //            createTest();
    //            return 0;
    //        freopen("out.txt", "w", stdout);
    
    
    
    
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    
    for(int i = 0; i < Test; ++i) {
        //                printf("Case #%d: ", i + 1);
        solve();
    }
    //
//#ifndef ONLINE_JUDGE
//    cout<<"\n" << 1.0 * (clock() - t1) / CLOCKS_PER_SEC<<endl;
//#endif
    
}