#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int best = 10;
        for(int mask = 0; mask<1024; mask++){
            bool good = 1;
            for(int i = 0; i<10; i++)
                if((mask&(1<<i)) && s[i]=='0') good = 0;
                else if(!(mask&(1<<i)) && s[i]=='1') good = 0;
            if(!good) continue;
            int a[2] = {0, 0};
            for(int i = 0; i<10; i++){
                a[i%2] += ((mask>>i)&1);
                int l0 = 4-i/2, l1 = 9-i-l0;
                if(a[0]+l0<a[1] || a[1]+l1<a[0]){
                    best = min(best, i+1); break;
                }
            }
        }
        cout << best << '\n';
    }
}