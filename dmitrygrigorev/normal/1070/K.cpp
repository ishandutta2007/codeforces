#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int S = 0;
    for (int i=0; i < n; i++) S += v[i];
    if (S%k!=0){
        cout << "No";
        return 0;
    }
    int u = 0;
    vector<int> ans;
    S/=k;
    for (int i=0; i < k; i++){
        int kek = 0;
        int du=u;
        while (u < n && kek < S){
            kek += v[u];
            u++;
        }
        if (kek != S){
            cout << "No";
            return 0;
        }
        ans.push_back(u-du);
    }
    if (ans.size() != k){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for (int i=0;i<ans.size(); i++) cout << ans[i] << " ";
}