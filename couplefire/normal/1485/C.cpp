#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        int bruh = min(y, (int)sqrt(x+1));
        long long ans = 0;
        for(int i = 1; i<=bruh; i++) ans += i-1;
        bruh++;
        for(int i = x/(bruh+1); i>=0; --i){
            int l = x/(i+1), r = (i == 0)?1000000009:x/i-1;
            if(l > y) break;
            r = min(r, y), l = max(l, bruh);
            ans += 1ll*i*(r-l+1);
        }
        cout << ans << endl;
    }
}