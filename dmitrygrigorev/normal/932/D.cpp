#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int LG = 21, V=400000;
int maxs[400000][LG], whm[400000][LG], cost[400000][LG], whc[400000][LG];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int last = 0;
    for (int i=0; i < V; i++){
        for (int j=0; j < LG; j++){
            maxs[i][j] = -1;
            whm[i][j] = -1;
            whc[i][j] = -1;
            cost[i][j] = -1;
        }
    }
    maxs[0][0] = 0;
    cost[0][0] = 0;
    int q;
    cin >> q;
    int vert = 1;
    for (int i=0; i < q; i++){
        int T, R, Q;
        cin >> T >> R >> Q;
        R ^= last;
        Q ^= last;
        //cout << T << " " << R << " " << Q << endl;
        if (T==1){
            R--;
            maxs[vert][0] = Q;
            cost[vert][0] = Q;
            whm[vert][0] = R;
            int nxt = R;
            int lvl = 1;
            while (whm[nxt][lvl-1] != -1){
                whm[vert][lvl] = whm[nxt][lvl-1];
                maxs[vert][lvl] = max(maxs[vert][lvl-1], maxs[nxt][lvl-1]);
                nxt = whm[nxt][lvl-1];
                lvl++;
            }
            if (maxs[nxt][lvl-1] != -1) maxs[vert][lvl] = max(maxs[vert][lvl-1], maxs[nxt][lvl-1]);
            int L = 19, nv = R;
            while (L >= 0){
                if (nv == -1) break;
                if (maxs[nv][L] == -1){
                    L--;
                    continue;
                }
                if (maxs[nv][L] < Q) nv = whm[nv][L];
                L--;
            }
            whc[vert][0] = nv;
            if (nv != -1){
                int nxt = nv;
                int lvl = 1;
                while (whc[nxt][lvl-1] != -1){
                    whc[vert][lvl] = whc[nxt][lvl-1];
                    cost[vert][lvl] = cost[vert][lvl-1] + cost[nxt][lvl-1];
                    nxt = whc[nxt][lvl-1];
                    lvl++;
                }
                if (cost[nxt][lvl-1] != -1) cost[vert][lvl] = cost[vert][lvl-1] + cost[nxt][lvl-1];
            }
            vert++;
        }
        else{
            R--;
            int ans = 0;
            int L = 19;
            while (L >= 0){
                if (R == -1) break;
                if (cost[R][L] == -1){
                    L--;
                    continue;
                }
                if (cost[R][L] <= Q){
                    ans += (1LL<<L);
                    Q -= cost[R][L];
                    R = whc[R][L];
                }
                L--;
            }
            cout << ans << endl;
            last =ans;
        }
    }
}