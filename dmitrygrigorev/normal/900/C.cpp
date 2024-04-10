#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) v[i]--;
    vector<int> ans(n);
    fill(ans.begin(), ans.end(), 0);
    int max1 = -1, max2 = -1;
    for (int i=0; i < n; i++){
        if (max1 < v[i]) ans[v[i]]--;
        else if (max2 < v[i]){
            ans[max1]++;
        }
        if (v[i] > max1){
            max2 = max1;
            max1 = v[i];
        }
        else if (v[i] > max2) max2 = v[i];
    }
    int answer = -1;
    int wh = -1;
    for (int i=n-1; i >= 0; i--){
        if (ans[i] >= answer){
            answer = ans[i];
            wh = i;
        }
    }
    cout << wh+1 << endl;
    return 0;
}