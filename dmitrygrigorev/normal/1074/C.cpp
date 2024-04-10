#include <bits/stdc++.h>
#define int long long

using namespace std;
#define TASKNAME ""
int g(vector<pair<int, int> > &v, int a, int b){
    return abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
}
int check(int a, int b, int c, vector<pair<int, int> > &v){
    return g(v, a, b) + g(v, a, c) + g(v, b, c);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for (int i=0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    vector<int> indixes;
    int mx = -1e9, ind=-1;
    int A = 0;
    for (int i=0; i < n; i++){
        if (v[i].first > mx){
            mx = v[i].first, ind = i;
        }
    }
    A += mx;
    indixes.push_back(ind);
    mx = 1e9, ind=-1;
    for (int i=0; i < n; i++){
        if (v[i].first < mx){
            mx = v[i].first, ind = i;
        }
    }
    A -= mx;
    indixes.push_back(ind);
    mx = -1e9, ind=-1;
    for (int i=0; i < n; i++){
        if (v[i].second > mx){
            mx = v[i].second, ind = i;
        }
    }
    A += mx;
    indixes.push_back(ind);
    mx = 1e9, ind=-1;
    for (int i=0; i < n; i++){
        if (v[i].second < mx){
            mx = v[i].second, ind = i;
        }
    }
    A -= mx;
    indixes.push_back(ind);
    int ans = 0;
    for (int i=0; i < indixes.size(); i++){
        for (int j=i+1; j < indixes.size(); j++){
            for (int k=0; k < n; k++){
                if (k==indixes[i] || k==indixes[j]) continue;
                ans = max(ans, check(indixes[i], indixes[j], k, v));
            }
        }
    }
    cout << ans << " ";
    for (int i=4; i <= n; i++) cout << 2*A << " ";
}