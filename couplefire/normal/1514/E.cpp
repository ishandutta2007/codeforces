#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 500500;
const int mod = 1e9 + 7;
const ll inf = 1e17 + 10;

int n;

int one(int u,int v) {
    cout << "1 " << u << " " << v << endl;
    int ct; cin >> ct;
    if(ct == -1) exit(0);
    return ct;
}

vector<int> pref(vector<int> path,int j) {
    vector<int> res;
    for(int i = 0; i <= j; i++) res.push_back(path[i]);
    return res;
}

int many(int u,vector<int> v) {
    cout << "2 " << u << " " << (int) v.size() << " ";
    for(int x : v) cout << x << " ";
    cout << endl;
    int ct; cin >> ct;
    if(ct == -1) exit(0);
    return ct;
}

vector<vector<int>> solve() {
    vector<vector<int>> res(n, vector<int> (n, 1));
    vector<int> path;
    for(int i = 0; i < n; i++) path.push_back(i);
    stable_sort(path.begin(),path.end(),one);
    int j = n - 2;
    for(int i = n - 1; i >= 0; i--) {
        if(i == j) {
            for(int l = 0; l <= i; l++) {
                for(int r = i + 1; r < n; r++) {
                    res[path[r]][path[l]] = 0; 
                }
            }
            j--;
        }
        while(many(path[i],pref(path,j))) j--;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        auto ans = solve();
        cout << 3 << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
        int ct; cin >> ct;
    }
}