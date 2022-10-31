#include <bits/stdc++.h>
using namespace std;

int ask(int x){
    cout << "? " << x+1 << endl;
    char c; cin >> c;
    if(c == 'N') return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> cnt(n);
    int ans = 0;
    if(k != 1) k /= 2;
    for(int i = k; i<n; i+=k){
        for(int j = 0; j<i; j+=k){
            if(j+i >= n) break;
            for(int a = 0; j+a*i<n; a++){
                for(int b = 0; b<k; b++) cnt[j+a*i+b] += ask(j+a*i+b);
            }
            cout << "R" << endl;
        }
    }
    for(int i = 0; i<n; i++) if(!cnt[i]) ans++;
    cout << "! " << ans << endl;
}