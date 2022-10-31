#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sum[n+1];
        sum[0] = 0;
        string s; cin >> s;
        for(int i = 0; i<n; i++){
            int a = s[i]-'0';
            --a;
            sum[i+1] = sum[i]+a;
        }
        int num[n*10];
        for(int i = 0; i<n*10; i++) num[i] = 0;
        num[n]++;
        long long ans = 0;
        for(int i = 1; i<=n; i++){
            ans += num[sum[i]+n];
            num[sum[i]+n]++;
        }
        cout << ans << endl;
    }
}