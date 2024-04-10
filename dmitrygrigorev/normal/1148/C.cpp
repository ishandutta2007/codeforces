#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int> > ans;
vector<int> v, pos;
void sw(int a, int b){
    int A = v[a], B = v[b];
    pos[A] = b, pos[B] = a;
    swap(v[a], v[b]);
    ans.push_back({a, b});
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    v.assign(n,-1);
    pos.assign(n,-1);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) v[i]--;
    for (int i=0;i<n;i++) pos[v[i]] = i;
    for (int i=0; i < n; i++){
        if (pos[i] == i) continue;
        int p = pos[i];
        if (abs(p - i) >= n/2){
            sw(p, i);
            continue;
        }
        if (p < n/2){
            sw(p, n-1);
            sw(n-1, i);
        }
        else{
            sw(0, p);
            if (i != 0){
                if (i < n/2){
                    sw(0, n-1);
                    sw(n-1, i);
                    sw(0, p);
                }
                else{
                    sw(0, i);
                    sw(0, p);
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i=0;i<ans.size();i++) cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
        //for (int j=0;j<n;j++) cout << v[j] << " ";
}