#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main(){
    int a,b;
    cin>>a>>b;
    int n = a + b - 2;
    ll ans = 4;
    while (n--){
        ans = ans * 2 % mod;
    }
    cout<<ans<<endl;
    return 0;
}