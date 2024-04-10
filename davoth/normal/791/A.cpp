#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int cnt=0;
    while(true){
        if(n>m) break;
        n*=3;
        m*=2;
        cnt++;
    }
    cout << cnt;
    return 0;
}