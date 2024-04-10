#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int arr[6];
int n;
vector<int> brr;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i<6; i++) cin >> arr[i];
    cin >> n;
    brr.resize(n);
    for(int i = 0; i<n; i++){
        cin >> brr[i];
    }
    sort(arr, arr+6);
    sort(brr.begin(), brr.end());
    brr.erase(unique(brr.begin(), brr.end()), brr.end());
    long long ans = 1000000009;
    set<pair<int, int>> st;
    int m = brr.size();
    if(m == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i<m; i++) st.insert({brr[i], i});
    // for(auto p : st) cout << p.first << " " << p.second << endl;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<6; j++){
            int dif = brr[i]-arr[j];
            int mx = 0;
            auto ii = st.lower_bound({arr[0]+dif, -1});
            if(ii == st.end()) continue;
            if((*ii).second != 0) continue;
            for(int k = 0; k<6; k++){
                auto it = st.lower_bound({dif+arr[k], -1});
                if(it != st.end()){
                    // cout << dif << " " << (*it).first
                    int ind = (*it).second;
                    if(ind == 0) continue;
                    if(k == 0) continue;
                    if(brr[ind-1] >= dif+arr[k-1]) mx = max(mx, brr[ind-1]-arr[k-1]);
                }
                else{
                    if(k == 0) continue;
                    if(brr[m-1] >= dif+arr[k-1]) mx = max(mx, brr[m-1]-arr[k-1]);
                }
            }
            if(brr[m-1] >= dif+arr[5]) mx = max(mx, brr[m-1]-arr[5]);
            ans = min(ans+0ll, mx-dif+0ll); 
        }
    }
    cout << ans << endl;
}