#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n+1];
    vector<int> b;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    a[n]=0;
    for(int i=0; i<n; i++){
        if(a[i]+1 != a[i+1]) b.push_back(a[i]);
    }
    cout << b.size() << '\n';
    for(int i : b){
        cout << i << ' ';
    }
    return 0;
}