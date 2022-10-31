#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int a; cin >> a;
            if((i+j)%2 == 0) cout << 720720 << " ";
            else cout << 720720-a*a*a*a << " ";
        }
        cout << endl;
    }
}