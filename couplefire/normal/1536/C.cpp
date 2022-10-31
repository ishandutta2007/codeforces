#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> arr(n);
        for(int i = 0; i<n; i++)
            arr[i] = (s[i]=='D');
        map<array<int, 2>, int> mp;
        int cnt[2];
        cnt[1] = arr[0], cnt[0] = !arr[0];
        mp[{cnt[1], cnt[0]}] = 1;
        cout << 1 << " ";
        for(int i = 1; i<n; i++){
            cnt[arr[i]]++;
            int a = cnt[1]/__gcd(cnt[1], cnt[0]);
            int b = cnt[0]/__gcd(cnt[1], cnt[0]);
            cout << ++mp[{a, b}] << " ";
        }
        cout << endl;
    }
}