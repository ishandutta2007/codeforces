#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    bool a[100];
    fill(a,a+100,true);
    for(int i=0; i<n; i++){
        int l,r;
        cin >> l >> r;
        for(int j=l-1; j<r; j++){
            a[j]=false;
        }
    }
    vector<int> b;
    for(int i=0; i<m; i++){
        if(a[i]) b.push_back(i+1);
    }
    cout << b.size() << '\n';
    for(int i=0; i<b.size(); i++){
        cout << b[i] << ' ';
    }
    return 0;
}