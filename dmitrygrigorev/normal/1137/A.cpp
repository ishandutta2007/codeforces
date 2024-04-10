#include <bits/stdc++.h>
#define int long long
using namespace std;
int matrix[1000][1000];
int posv[1000][1000], posh[1000][1000];
int amountv[1000], amounth[1000];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> matrix[i][j];
    vector<pair<int, int> > v;
    for (int i=0; i < n; i++){
        v.clear();
        for (int j=0; j < m; j++) v.push_back({matrix[i][j], j});
        sort(v.begin(), v.end());
        int cur = 0, last = -1;
        for (int j=0; j < m; j++){
            if (v[j].first > last){
                last = v[j].first, cur++;
            }
            posh[i][v[j].second] = cur;
        }
        amounth[i] = cur;
    }
    for (int i=0; i < m; i++){
        v.clear();
        for (int j=0; j < n; j++) v.push_back({matrix[j][i], j});
        sort(v.begin(), v.end());
        int cur = 0, last = -1;
        for (int j=0; j < n; j++){
            if (v[j].first > last){
                last = v[j].first, cur++;
            }
            posv[v[j].second][i] = cur;
        }
        amountv[i] = cur;
    }
    for (int i=0;i<n;i++) {
        for (int j=0; j < m; j++){
            //cout << posh[i][j] << " " << posv[i][j] << endl;
            //continue;
            int value = max(posh[i][j], posv[i][j]);
            int answer = max(amounth[i] + value - posh[i][j], amountv[j] + value-posv[i][j]);
            cout << answer << " ";
        }
        cout << "\n";
    }
}