#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    cout << ((n+k-1)/k)*((m+k-1)/k) << endl;
    // cout << ceil((0.0+n)/k)*ceil((0.0+m)/k) << endl;
}