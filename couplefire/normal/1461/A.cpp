#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        char arr[3] = {'a', 'b', 'c'};
        int cur = 0;
        for(int i = 0; i<n; i++){
            cout << arr[cur = (cur+1)%3];
        }
        cout << endl;
    }
}