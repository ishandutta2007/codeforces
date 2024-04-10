#include <bits/stdc++.h>
using namespace std;
#define MAXN 2100ll
#define MOD 1000000007ll
#define INF 1000000000000000009ll
#define int long long
#define Point pair<int, int>
#define x first
#define y second

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int ckmin(int &a, int b){return (b<a)?a=b:a;}
int ckmax(int &a, int b){return (b>a)?a=b:b;}

struct Line{
    int m, c, id;
    Line(int _m, int _c, int _id): m(_m), c(_c), id(_id){}
    Line(Point p, int _m, int _id): m(_m), id(_id){
        c = -m*p.x+p.y;
    }
    int eval(int x){return x*m+c;}
    int intersect(Line l){
        return (l.c-c)/(m-l.m);
    }
    int sum(int l, int r){
        int bruh = (l+r)*(r-l+1)/2; bruh %= MOD; grow(bruh, m%MOD);
        int lol = c%MOD; if(lol<0) lol += MOD; grow(lol, (r-l+1)%MOD);
        return add(bruh, lol); 
    }
    bool operator < (const Line& l) const{
        if(m != l.m) return m < l.m;
        return c > l.c;
    }
    bool operator == (const Line& l) const{
        return m == l.m;
    }
};

int n, m, q;
vector<array<int, 2>> adj[MAXN];
int dp[MAXN][MAXN];
int mxadj[MAXN];
stack<Line> hull;
vector<Line> lines;
array<int, 2> ranges[MAXN];
int ans;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i<m; i++){
        int a, b, w; cin >> a >> b >> w; --a; --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        ckmax(mxadj[a], w); ckmax(mxadj[b], w);
    }
    for(int v = 0; v<n; v++) dp[v][0] = -INF;
    dp[0][0] = 0;
    for(int len = 1; len<MAXN; len++){
        int _ans = 0;
        for(int v = 0; v<n; v++){
            dp[v][len] = -INF;
            for(auto u : adj[v]) ckmax(dp[v][len], dp[u[0]][len-1]+u[1]);
            ckmax(_ans, dp[v][len]);
        }
        if(len <= q) inc(ans, _ans%MOD);
    }
    if(q < MAXN){
        cout << ans << endl;
        return 0;
    }
    for(int v = 0; v<n; v++) if(dp[v][MAXN-1] >= 0) lines.push_back(Line({MAXN-1, dp[v][MAXN-1]}, mxadj[v], -1));
    sort(lines.begin(), lines.end());
    lines.erase(unique(lines.begin(), lines.end()), lines.end());
    n = lines.size();
    for(int v = 0; v<n; v++) lines[v].id = v;
    for(auto l : lines){
        ranges[l.id] = {q+1, q};
        while(!hull.empty()){
            Line curl = hull.top();
            int res = l.intersect(curl)+1;
            if(res <= ranges[curl.id][0]){
                ranges[l.id][0] = ranges[curl.id][0];
                ranges[curl.id] = {q+1, q};
                hull.pop();
            }
            else if(res <= ranges[curl.id][1]){
                ranges[curl.id][1] = res-1;
                ranges[l.id][0] = res;
                hull.push(l);
                break;
            }
            else break;
        }
        if(hull.empty() || ranges[hull.top().id][1] != q) ranges[l.id] = {MAXN, q}, hull.push(l);
    }
    for(int v = 0; v<n; v++) inc(ans, lines[v].sum(ranges[v][0], ranges[v][1]));
    cout << ans << endl;
}