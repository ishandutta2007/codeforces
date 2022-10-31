#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%2){
            cout << "NO" << endl;
            continue;
        }
        int bruh1 = (int)(sqrt(.0+n));
        int bruh2 = (int)(sqrt(.0+n/2.0));
        if(bruh1*bruh1 == n || 2*bruh2*bruh2 == n){
            cout << "YES" << endl;
            continue;
        }
        else{
            cout << "NO" << endl;
            continue;
        }
    }
}