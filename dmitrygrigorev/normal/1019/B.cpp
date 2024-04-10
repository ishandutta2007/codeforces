#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int, int> ask(int a, int b){
    cout << "? " << a+1 << endl;
    int x;
    cin >> x;
    cout << "? " << b+1 << endl;
    int y;
    cin >> y;
    if (x==y){
        cout << "! " << b+1 << endl;
        exit(0);
    }
    return make_pair(x, y);
}
signed main() {
    int n;
    cin >> n;
    if (n%4 != 0){
        cout << "! -1" << endl;
        return 0;
    }
    pair<int, int> p = ask(0, n/2);
    int df = p.first - p.second;
    int L = 1, R = n/2-1;
    while (true){
        int M = (L+R)/2;
        pair<int, int> q = ask(M, M+n/2);
        int Df = q.first - q.second;
        if (Df*df > 0) L = M+1;
        else R = M-1;
    }
}