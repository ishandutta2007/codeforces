#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int cn=n,cm=m;
    n--;
    m--;
    int cnt=1;
    while(n){
        n--;
        cnt++;
    }
    while(m){
        m--;
        cnt++;
    }
    cout << cnt << '\n' << 1 << ' ' << 1 << '\n';
    while(cn>1){
        cout << cn << ' ' << 1 << '\n';
        cn--;
    }
    while(cm>1){
        cout << 1 << ' ' << cm << '\n';
        cm--;
    }
    return 0;
}