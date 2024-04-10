#include <bits/stdc++.h>
using namespace std;

vector<char> id = {'A', 'N', 'T', 'O'};
unordered_map<char, int> mp;

void solve(){
    string s; cin >> s;
    int n = s.length();
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        arr[i] = mp[s[i]];
    vector<int> orig = arr;
    vector<int> permu = {0, 1, 2, 3};
    vector<int> bpermu; long long bans = -1;
    do{
        for(int i = 0; i<n; i++)
            arr[i] = permu[arr[i]];
        vector<int> cnt(4, 0);
        long long ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = arr[i]+1; j<4; j++)
                ans += cnt[j];
            cnt[arr[i]]++;
        }
        if(ans > bans) bpermu = permu, bans = ans;
        arr = orig;
    } while(next_permutation(permu.begin(), permu.end()));
    sort(arr.begin(), arr.end(), [&](int a, int b){return bpermu[a] < bpermu[b];});
    for(int i = 0; i<n; i++)
        cout << id[arr[i]];
    cout << endl;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 0; i<4; i++)
        mp[id[i]] = i;
    int t; cin >> t;
    while(t--) solve();
}