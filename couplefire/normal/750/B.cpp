#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int cur = 0;
    for(int i = 0; i<n; ++i){
        int a; string s; cin >> a >> s;
        if(cur==0 && s[0]!='S'){
            cout << "NO" << '\n';
            return 0;
        }
        if(cur==20000 && s[0]!='N'){
            cout << "NO" << '\n';
            return 0;
        }
        if(s[0]=='N') cur -= a;
        if(s[0]=='S') cur += a;
        if(cur<0 || cur>20000){
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << (cur==0?"YES":"NO") << '\n';
}