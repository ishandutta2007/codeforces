#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int mn = (max(a, b)-min(a, b))/2;
        int mx = (a+b)-mn;
        if((a+b)%2==0){
            cout << (mx-mn+2)/2 << '\n';
            for(int i = mn; i<=mx; i+=2)
                cout << i << ' ';
            cout << '\n';
        } else{
            cout << mx-mn+1 << '\n';
            for(int i = mn; i<=mx; ++i)
                cout << i << ' ';
            cout << '\n';
        }
    }
}