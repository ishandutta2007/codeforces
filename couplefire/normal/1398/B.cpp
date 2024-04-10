#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int arr[s.length()+1];
        int n = s.length();
        for(int i = 0; i<n; i++) arr[i] = s[i]-'0';
        arr[n] = 0;
        vector<int> chunks;
        for(int i = 0; i<n;){
            int j;
            for(j = i; j<=n; j++){
                if(arr[j] == 0){
                    if((j - i) != 0){
                        chunks.push_back(j-i);
                    }
                    break;
                }
            }
            i = j+1;
        }
        sort(chunks.begin(), chunks.end());
        reverse(chunks.begin(), chunks.end());
        int ans = 0;
        for(int i = 0; i<chunks.size(); i+=2){
            ans += chunks[i];
        }
        cout << ans << endl;
    }
}