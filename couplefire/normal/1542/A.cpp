#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt[2] = {0, 0};
        for(int i = 0; i<2*n; i++){
            int a; cin >> a;
            cnt[a%2]++;
        }
        cout << (cnt[0]==cnt[1]?"Yes":"No") << endl;
    }
}