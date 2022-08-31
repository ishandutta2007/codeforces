#include <bits/stdc++.h>
#define int long long
using namespace std;
int ctr[100];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        for (int j=0; j < x; j++){
            int y;
            cin >> y;
            ctr[y-1]++;
        }
    }
    vector<int> ans;
    for (int i=0;i<100;i++) if (ctr[i] == n) ans.push_back(i+1);
    //cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i] << " ";

}