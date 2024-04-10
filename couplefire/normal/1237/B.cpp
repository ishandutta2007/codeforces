#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<array<int, 2>> arr(n);
    for(int i = 0; i<n; i++){
        int a; cin >> a; --a;
        arr[a][0] = i;
    }
    for(int i = 0; i<n; i++){
        int a; cin >> a; --a;
        arr[a][1] = i;
    }
    sort(arr.begin(), arr.end());
    int best = 0, ans = 0;
    for(int i = 0; i<n; i++){
        if(best > arr[i][1]) ans++;
        best = max(best, arr[i][1]);
    }
    cout << ans << endl;
}