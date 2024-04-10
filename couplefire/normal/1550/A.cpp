#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int s; cin >> s;
        int sum = 0, cnt = 0;
        for(int i = 1; sum < s; i+=2){
            sum += i; cnt++;
        }
        cout << cnt << endl;
    }
}