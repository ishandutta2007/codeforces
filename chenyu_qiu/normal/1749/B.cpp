#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long ans = 0;
        std::vector<int> a(n) , b(n);
        for(int & it : a) {
            cin >> it;
            ans += it;
        }       
        for(int & it : b) {cin >> it; ans += it;}
        ans -= * max_element(b.begin(), b.end());
        cout << ans << "\n";
    }
    
    return 0;
}