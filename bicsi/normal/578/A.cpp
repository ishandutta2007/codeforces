#include <bits/stdc++.h>

using namespace std;

int a, b;

double calc(int O) {
    if(O <= 1) return 0;
    if(O%2 == 0) return 1.0*(a+b)/O;
    else return 1.0*(a-b)/(O-1);
}

double c(int O) {
    if(calc(O) >= b) return calc(O);
    return 1e17;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    cin>>a>>b;

    if(a < b) {
        cout<<-1;
        return 0;
    }
    int O = a / b;

    cout<<fixed<<setprecision(12)<<min(min(c(O-1), c(O)), c(O+1));




    return 0;
}