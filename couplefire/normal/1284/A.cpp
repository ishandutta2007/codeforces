#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int n, m; cin >> n >> m;
    string arr[n];
    string aa[m];
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<m; i++) cin >> aa[i];
    int q; cin >> q;
    while(q--){
        int year; cin >> year;
        cout << arr[(year-1)%n]+aa[(year-1)%m] << endl;
    }
}