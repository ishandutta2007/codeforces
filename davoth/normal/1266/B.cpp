#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 1e2 + 10;

int n;
int main(){
    fast_io;
    cin >> n;
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        if(x<=14){
            cout << "NO\n";
            continue;
        }
        if(x%14<=6 && x%14>=1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}