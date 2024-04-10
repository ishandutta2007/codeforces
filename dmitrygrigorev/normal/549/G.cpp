#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    for (int i=0;i<n;i++) v[i] -= (n-i);
    sort(v.begin(), v.end());
    for (int i=0;i<n-1;i++){
        if (v[i] == v[i+1]){
            cout << ":(";
            return 0;
        }
    }
    for (int i=0;i<n;i++) v[i] += (n-i);
    for (int i=0;i<n;i++) cout << v[i] << " ";
}