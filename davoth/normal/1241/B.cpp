#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_N = 1e5 + 1, MOD = 1e8;
using namespace std;
int main() {
    ll q;
    cin >> q;
    while(q--){

        string s,t;
        cin >> s >> t;
        ll c=0;
        for(ll i=0; i<s.size(); i++){
            for(ll j=0; j<s.size(); j++){
                if(s[i]==t[j]){
                    cout << "YES\n";
                    c=1;
                    break;
                }
            }
            if(c==1) break;
        }
        if(c==0) cout << "NO\n";
    }
    return 0;
}