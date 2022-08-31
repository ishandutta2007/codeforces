#include <bits/stdc++.h>
#define int long long
using namespace std;
int ask(int number){
    cout << number << endl;
    int res;
    cin >> res;
    if (res == 0){
        exit(0);
    }
    return res;
}
signed main() {
    int m, n;
    cin >> m >> n;
    vector<bool> tr;
    for (int i=0; i < n; i++){
        int res = ask(1);
        if (res == 1) tr.push_back(true);
        else tr.push_back(false);
    }
    int L = 2, R = m;
    int ctr = n;
    while (true){
        int M = (L+R)/2;
        int res = ask(M);
        if (!tr[ctr%n]) res *= -1;
        ctr++;
        if (res == 1) L = M+1;
        else R = M-1;
    }
    return 0;
}