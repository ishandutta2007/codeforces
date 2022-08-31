#include <bits/stdc++.h>
using namespace std;
const int K = 100001;
vector<vector<pair<int, int> > > bad(8);
vector<vector<int> > del(100001);
int dp[8][500], suff[8][500];
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> od, Od, Mask, mask;
    int u1 = 0, u2 = 0, u3 = 0;
    while (u1 < del[a].size() && u2 < del[b].size()){
        if (del[a][u1] < del[b][u2]){
            od.push_back(del[a][u1]);
            mask.push_back(1);
            u1++;
        }
        else if (del[a][u1] == del[b][u2]){
            od.push_back(del[a][u1]);
            mask.push_back(3);
            u1++, u2++;
        }
        else{
            od.push_back(del[b][u2]);
            mask.push_back(2);
            u2++;
        }
    }
    while (u1 < del[a].size()){
        od.push_back(del[a][u1]);
        mask.push_back(1);
        u1++;
    }
    while (u2 < del[b].size()){
        od.push_back(del[b][u2]);
        mask.push_back(2);
        u2++;
    }
    u1 = 0;
    while (u1 < od.size() && u3 < del[c].size()){
        if (od[u1] < del[c][u3]){
            Od.push_back(od[u1]);
            Mask.push_back(mask[u1]);
            u1++;
        }
        else if (od[u1] == del[c][u3]){
            Od.push_back(od[u1]);
            Mask.push_back(mask[u1] | 4);
            u1++;
            u3++;
        }
        else{
            Od.push_back(del[c][u3]);
            Mask.push_back(4);
            u3++;
        }
    }
    while (u1 < od.size()){
        Od.push_back(od[u1]);
        Mask.push_back(mask[u1]);
        u1++;
    }
    while (u3 < del[c].size()){
        Od.push_back(del[c][u3]);
        Mask.push_back(4);
        u3++;
    }
    //for (int i=0; i < Od.size(); i++) cout << Od[i] << " ";
    //cout << endl;
    //for (int i=0; i < Od.size(); i++) cout << Mask[i] << " ";
    //cout << endl;
    for (int i=0; i < 8; i++) dp[i][0] = 0;
    for (int i=0; i < 8; i++) suff[i][0] = 0;
    for (int i=0; i < Od.size(); i++){
        for (int j=0; j < 8; j++) dp[j][i+1] = dp[j][i] + (Mask[i] == j);
    }
    for (int i=0; i < Od.size(); i++){
        for (int j=0; j < 8; j++) suff[j][i+1] = suff[j][i] + (Mask[Od.size()-i-1] == j);
    }
    int ans = 0;
    for (int i=0; i < Od.size(); i++){
        ans += i * (Od.size() - i - 1);
    }
    for (int i=0; i < Od.size(); i++){
        int N = Mask[i];
        if (N==7) ans++;
        int nd = N^7;
        int bt = 0;
        for (int j=0; j < 3; j++){
            int ba = N & (1<<j);
            if (ba != 0) bt++;
        }
        if (bt >= 2){
            for (int j=0; j < 8; j++){
                int ba = (j & nd);
                if (ba == nd) ans += dp[j][i] + suff[j][Od.size() - i - 1];
            }
        }
        for (int j=0; j < bad[N].size(); j++){
            ans -= dp[bad[N][j].first][i] * suff[bad[N][j].second][Od.size() - i - 1];
        }
    }
    cout << ans << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int j=1; j < 8; j++){
        int q = 0;
        for (int i=1; i < 8;i++){
            for (int k=1; k < 8; k++){
                vector<int> a;
                a.push_back(0), a.push_back(1), a.push_back(2);
                vector<int> b;
                b.push_back(i), b.push_back(j), b.push_back(k);
                bool ab = false;
                do{
                    bool th = true;
                    for (int p=0; p < 3; p++){
                        int ba = (1<<(a[p])) & b[p];
                        if (ba == 0) th = false;
                    }
                    ab |= th;
                }
                while (next_permutation(a.begin(), a.end()));
                if (!ab) bad[j].push_back({i, k});
            }
        }
    }
    for (int i=1; i < K; i++){
        for (int j=i; j < K; j+=i) del[j].push_back(i);
    }
    int T;
    cin >> T;
    for (int i=0; i < T; i++) solve();
    return 0;
}