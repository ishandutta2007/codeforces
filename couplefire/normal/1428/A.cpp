#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a == c){
            cout << abs(d-b) << endl;
        }
        else if(b == d){
            cout << abs(a-c) << endl;
        }
        else{
            cout << abs(c-a)+abs(d-b)+2 << endl;
        }
    }
}