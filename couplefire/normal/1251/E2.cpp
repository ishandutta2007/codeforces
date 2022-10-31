#include <bits/stdc++.h>
using namespace std;

bool pairsort(pair<long long, long long> a, pair<long long, long long> b){
    if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    return a.second > b.second;
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long q; cin >> q;
    while(q--){
        long long n; cin >> n;
        pair<long long, long long> arr[n];
        for(long long i = 0; i<n; i++) cin >> arr[i].first >> arr[i].second;
        sort(arr, arr+n, pairsort);
        long long dif = 0;
        long long ans = 0;
        multiset<long long> mi;
        for(long long i = n-1; i>=0; i--){
            mi.insert(arr[i].second);
            if(arr[i].first-i-dif == 1){
                ans += *mi.begin();
                mi.erase(mi.begin());
                dif++;
            }
        }
        cout << ans << endl;
    }
}