#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
bool zpr(int v){
    cout << "? " << v << endl;
    int a, b;
    cin >> a;
    cout << "? " << v + 1 << endl;
    cin >> b;
    return a < b;
}
void solve(){
    int n;
    cin >> n;
    if (n == 1){
        cout << "! 1";
        return;
    }
    int l = 1, r = n;
    while (l + 1 < r){
        int m = l + r >> 1;
        if (zpr(m))
            r = m;
        else l = m;
    }
    if (zpr(l)){
        cout << "! " << l;
    } else{
        cout << "! " << r;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}