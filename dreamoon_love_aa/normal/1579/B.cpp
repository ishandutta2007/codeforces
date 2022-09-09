//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define PB push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int MAX = 1e2, MOD = 1e9 + 7;


void solve(){
    int n, check[51] = {}, cnt[51] = {}, mx = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    for(int i = 0;i < n;i++){
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i = n - 1;i >= 0;i--){
        for(int j = i;j >= 0;j--){
            if(mx == a[j]){
                if(i == j){
                    cnt[mx]--;
                    if(!cnt[mx])
                        mx--;
                    break;
                }
                ans.PB({{j + 1, i + 1}, 1});
                for(int k = j;k < i;k++){
                    a[k] = a[k + 1];
                }
                a[i] = mx;
                cnt[mx]--;
                if(!cnt[mx])
                    mx--;
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0;i < ans.size();i++){
        cout << ans[i].F.F << " " << ans[i].F.S << " " << ans[i].S << '\n';
    }
}

int main(){
    IOS
        int t;
    cin >> t;
    while(t--){
        solve();
    }
}