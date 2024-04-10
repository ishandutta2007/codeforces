#include <bits/stdc++.h>
#define int long long

using namespace std;
#define TASKNAME ""
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> vert(n);
    for (int i=0; i < n; i++) cin >> vert[i];
    sort(vert.begin(), vert.end());
    vector<int> hor;
    for (int i=0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (a!=1) continue;
        hor.push_back(b);
    }
    sort(hor.begin(), hor.end());
    int ans = n+m;
    int u=0;
    for (int i=-1; i < n; i++){
        int A = 1e9;
        if (i < n-1) A = vert[i+1];
        while (u < hor.size() && hor[u] < A) u++;
        ans = min(ans, i+1+(int)hor.size() - u);
    }
    cout << ans;
}