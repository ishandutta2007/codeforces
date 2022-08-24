#include <bits/stdc++.h>
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    int num = 1000000 - (k % 2000);
    int req = (num + k)/2000;
    cout << 2000 << "\n";
    for (int i=0; i < 1998; i++) cout << 0 << " ";
    cout << -(num-req) << " ";
    cout << num << endl;


}