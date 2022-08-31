#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
int INF = 1e8;
int get(vector<int> &x){
    return x[0]+10*x[1]+100*x[2]+1000*x[3];
}
vector<pair<short, short> > per[725][9][9][9];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    vector<int> pos(10000);
    vector<int> pval;
    fill(pos.begin(), pos.end(), -1);
    vector<vector<int> > vect;
    for (int i=0; i < 10000; i++){
        vector<int> h;
        int cp = i;
        for (int j=0; j < 4; j++){
            h.push_back(cp%10);
            cp /= 10;
        }
        sort(h.begin(), h.end());
        vect.push_back(h);
        int num = get(h);
        if (pos[num] != -1) continue;
        pos[num] = pval.size();
        pval.push_back(num);
    }
    int dp[pval.size()];
    for (int i=0; i < pval.size(); i++) dp[i] = INF;
    dp[0] = 0;
    int tt = 0;
    for (int wanted=1; wanted < 10; wanted++) for (int flr = 1; flr < 10; flr++) for (int fin=1; fin < 10; fin++) {
        if (wanted==fin)continue;
        for (int j=0; j < pval.size(); j++){
            vector<int> q;
            vector<int> rl = vect[pval[j]];
            if (wanted == flr){
                if (rl[0] == 0){
                    rl[0] = fin;
                    sort(rl.begin(), rl.end());
                    int gt = pos[get(rl)];
                    per[j][flr][wanted][fin].push_back({gt, 0});
                    continue;
                }
            }
            for (int p=0; p < 4; p++) if (rl[p] || p == 3) q.push_back(p);
            for (int t=0; t < 1<<(q.size()); t++){
                vector<int> vll, neb;
                bool abl = true;
                for (int e=0; e < q.size(); e++){
                    int ba = (1<<e)&t;
                    if (!ba && rl[q[e]]) vll.push_back(rl[q[e]]);
                    if (ba && rl[q[e]] == wanted) abl = false;
                    if (ba && rl[q[e]]) neb.push_back(rl[q[e]]);
                }
                if (!abl) continue;
                int mn=INF,mx=-INF;
                for (int u=0; u < vll.size(); u++) mx = max(mx, vll[u]);
                for (int u=0; u < vll.size(); u++) mn = min(mn, vll[u]);
                int zn = abs(wanted - flr);
                if (vll.size()){
                    zn = mx-mn + abs(mn - flr) + abs(mx - wanted);
                    zn = min(zn, mx-mn + abs(mn - wanted) + abs(mx - flr));
                }
                if (neb.size() == 4) continue;
                neb.push_back(fin);
                while (neb.size() < 4) neb.push_back(0);
                sort(neb.begin(), neb.end());
                per[j][flr][wanted][fin].push_back({pos[get(neb)], zn});
            }
        }
    }
    int flr = 1;
    for (int it=0; it < n; it++){
        int wanted = v[it].first, fin = v[it].second;
        int dp2[pval.size()];
        for (int i=0; i < pval.size(); i++) dp2[i] = INF;
        for (int j=0; j < pval.size(); j++){
            for (int e=0; e < per[j][flr][wanted][fin].size(); e++){
                int F = per[j][flr][wanted][fin][e].first, S = per[j][flr][wanted][fin][e].second;
                dp2[F] = min(dp2[F], dp[j] + S);
            }
        }
        for (int i=0; i < pval.size(); i++) dp[i] = dp2[i];
        flr = wanted;
    }
    int ans = INF;
    for (int i=0; i < pval.size(); i++){
        vector<int> q, rl = vect[pval[i]];
        int th = INF;
        for (int p=0; p < 4; p++) q.push_back(p);
        do{
            int he = dp[i];
            int fl = flr;
            for (int z=0; z < 4; z++){
                if (rl[q[z]] != 0){
                    he += abs(fl - rl[q[z]]);
                    fl = rl[q[z]];
                }
            }
            th = min(th, he);
        }
        while (next_permutation(q.begin(), q.end()));
        ans = min(ans, th);
    }
    cout << ans+2*n;


}