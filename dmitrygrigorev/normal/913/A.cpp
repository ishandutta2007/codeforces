#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n, m;
    cin >> n >> m;
    if (n >= 50){
        cout << m << endl;
    }
    else{
        int A = 1;
        for (int i=0; i < n; i++) A *= 2;
        cout << m%A << endl;
    }
    return 0;
}