#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    string arr[n];
    unordered_map<string, int> mp;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        mp[arr[i]]--;
        for(int j = i+1; j<n; j++){
            mp[arr[j]]--;
            string s(k, ' ');
            for(int a = 0; a<k; a++){
                if(arr[i][a] == arr[j][a]) s[a] = arr[i][a];
                else{
                    s[a] = 'S'+'T'+'E'-arr[i][a]-arr[j][a];
                }
            }
            ans += mp[s];
        }
        for(int j = i+1; j<n; j++){
            mp[arr[j]]++;
        }
    }
    cout << ans << endl;
}