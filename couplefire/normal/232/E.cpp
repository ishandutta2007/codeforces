#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define MAXN 505

struct Node{int x1, y1, x2, y2, id;} query;
bitset<MAXN> a[MAXN][MAXN], b[MAXN][MAXN];
int n, m, q;
vector<Node> queries;
char grid[MAXN][MAXN];
bool ans[600006] = {0};

void solve(int l, int r, vector<Node> &v){
    int mid = (l+r)>>1, siz = v.size();
    if(!siz || l > r) return;
    for(int i = mid; i>=l; i--){
        for(int j = m; j>=1; j--){
            a[i][j].reset();
            if(grid[i][j] == '#') continue;
            if(i == mid) a[i][j][j] = 1;
            else a[i][j] |= a[i+1][j];
            if(j != m) a[i][j] |= a[i][j+1];
        }
    }
    for(int i = mid; i<=r; i++){
        for(int j = 1; j<=m; j++){
            b[i][j].reset();
            if(grid[i][j] == '#') continue;
            if(i == mid) b[i][j][j] = 1;
            else b[i][j] |= b[i-1][j];
            if(j != 1) b[i][j] |= b[i][j-1];
        }
    }
    // cout << a[1][1].count() << endl;
    vector<Node> v1, v2;
    for(int i = 0; i<siz; i++){
        if(v[i].x2 < mid) v1.push_back(v[i]);
        else if(v[i].x1 > mid) v2.push_back(v[i]);
        else ans[v[i].id] = (a[v[i].x1][v[i].y1]&b[v[i].x2][v[i].y2]).any();
    }
    solve(l, mid-1, v1); solve(mid+1, r, v2);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) scanf("%s", grid[i+1]+1);
    scanf("%d", &q);
    for(int i = 0; i<q; i++){
        query.id = i;
        scanf("%d%d%d%d", &query.x1, &query.y1, &query.x2, &query.y2);
        queries.push_back(query);
    }
    solve(1, n, queries);
    for(int i = 0; i<q; i++) if(ans[i]) printf("Yes\n"); else printf("No\n");
}