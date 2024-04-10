#include<bits/stdc++.h>
using namespace std;
struct Query{int l; int r; int ind;};
bool cmp(Query &a, Query &b){
    return (a.l < b.l);
}
int INF = 1e8;
int code[19][19];
int nxt[300001][190];
signed main() {  
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    vector<Query> kek;
    for (int i=0; i < q; i++){
        int l, r;
        cin >> l >> r;
        kek.push_back({l-1, r-1, i});
    }
    sort(kek.begin(), kek.end(), cmp);
    vector<bool> ans(q);
    int edges[19][19];
    for (int i=0; i < 19; i++) for (int j=0; j < 19; j++) edges[i][j] = INF;
    int u = q-1;
    int dst[19];
    bool used[19];
    int cur=0;
    for (int i=0; i < 19; i++) for (int j=i; j < 19; j++){
        code[i][j] = cur++;
        code[j][i] = code[i][j];
    }
    for (int i=0; i < 190; i++) nxt[n][i] = INF;
    for (int i=n-1; i >= 0; i--){
        for (int j=0; j < 19; j++) for (int k=j; k < 19; k++){
            int A = (1<<j)&v[i], B = (1<<k)&v[i];
            int C = code[j][k];
            if (A!=0 && B != 0){
                edges[j][k] = i;
                nxt[i][C] = i;
            }
            else nxt[i][C] = nxt[i+1][C];
        }
        while (u >= 0 && kek[u].l == i){
            int R = kek[u].r, I = kek[u].ind;
            for (int j=0; j < 19; j++) dst[j] = INF;
            for (int j=0; j < 19; j++) used[j]=false;
            for (int j=0; j < 19; j++){
                int ba = (1<<j)&v[i];
                if (ba != 0) dst[j] = i;
            }
            for (int j=0; j < 19; j++){
                int mn = INF+1, index = -1;
                for (int k=0; k < 19; k++){
                    if (used[k]) continue;
                    if (dst[k] < mn){
                        mn = dst[k], index=k;
                    }
                }
                used[index] = true;
                if (mn > n) continue;
                for (int k=0; k < 19; k++){
                    if (used[k]) continue;
                    int tet = nxt[mn][code[index][k]];
                    dst[k] = min(dst[k], tet);
                }
            }
            bool can = false;
            for (int j=0; j < 19; j++){
                int ba = (1<<j)&v[R];
                if (ba != 0 && dst[j] <= R) can = true;
            }
            ans[I] = can;
            u--;

        }
    }
    for (int i=0;i<q;i++){
        if (ans[i]) cout << "Shi\n";
        else cout << "Fou\n";
    }
}