#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    int a1[n];
    int a2[n];
    map<int, int> mp;
    for(int i = 0; i<n; i++){
        cin >> a1[i];
        a2[i] = a1[i];
    }
    sort(a2, a2+n);
    for(int i = 0; i<n; i++){
        mp[a2[i]] = a2[(i+1)%n];
    }
    for(int i = 0; i<n; i++){
        cout << mp[a1[i]] << " ";
    }
    cout << endl;
}