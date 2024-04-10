#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i=0; i < n; i++){
        int l;
        cin >> l;
        v[i].first = l;
    }
    for (int i=0; i < n; i++){
        int l;
        cin >> l;
        v[i].second = l;
    }
    vector<pair<int, int> > cv=v;
    vector<int> ans(n);
    fill(ans.begin(), ans.end(), -1);
    int kek = n;
    while (true){
        vector<int> ind;
        int ctr=0;
        for (int i=0; i < n; i++) if (ans[i] == -1){
            ctr++;
            if (cv[i].first == 0 && cv[i].second == 0) ind.push_back(i);
        }
        if (ctr == 0) break;
        if (ind.size() == 0){
            cout << "NO";
            return 0;
        }
        for (int i=0; i < ind.size(); i++) ans[ind[i]] = kek;
        int L = 0, R = ind.size();
        int u = 0;
        for (int i=0; i < n; i++){
            if (u < ind.size() && ind[u] == i){
                u++, L++, R--;
                continue;
            }
            if (ans[i] != -1) continue;
            cv[i].first -= L, cv[i].second -= R;
            if (cv[i].second <0 || cv[i].first < 0){
                cout << "NO";
                return 0;
            }
        }
        kek--;
    }
    for (int i=0; i < n; i++){
        int L = 0, R=0;
        for (int j=0; j < i; j++) if (ans[j] > ans[i]) L++;
        for (int j=i+1; j < n; j++) if (ans[j] > ans[i]) R++;
        if (L != v[i].first || R != v[i].second){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++) cout << ans[i] << " ";

}