#include <bits/stdc++.h>
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> k(n), mn(n);
    fill(k.begin(), k.end(), 0);
    fill(mn.begin(), mn.end(), 1e9);
    for (int i=0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        k[u]++;
        if (v < u) v += n;
        mn[u] = min(mn[u], v-u);
    }
    int laps = 0;
    for (int i=0; i < n; i++) laps = max(laps, k[i] - 1);
    int ans = laps*n;
    for (int i=0; i < n; i++){
        int mv = 0;
        for (int j=0; j < n; j++){
            if (k[j] < laps) continue;
            if (k[j] == laps){
                if (laps!=0){
                int D;
                if (j < i) D = i-j;
                else D = n - (j-i);
                mv = max(mv, max((int) 0, mn[j]-D));
                }
                continue;
            }
            else{
                int dist = j-i;
                if (j < i) dist = n - (i - j);
                mv = max(mv, dist + mn[j]);
            }
        }
        cout << ans+mv << " ";
    }
}