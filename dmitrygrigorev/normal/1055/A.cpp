#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, n;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    if (s==1){
        cout << "YES";
        return 0;
    }
    if (a[0] == 0){
        cout << "NO";
        return 0;
    }
    s--;
    if (a[s] == 1){
        cout << "YES";
        return 0;
    }
    if (b[s] == 0){
        cout << "NO";
        return 0;
    }
    for (int i=s+1; i < n; i++){
        if (a[i]==1 && b[i]==1){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}