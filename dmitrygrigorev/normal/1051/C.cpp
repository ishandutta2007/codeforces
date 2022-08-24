#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[100];
signed main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) v[i]--;
    for (int i=0; i < n; i++) h[v[i]]++;
    int sole = 0, th = 0;
    for (int i=0;i<100;i++){
        if (h[i] == 1) sole++;
        if (h[i] >= 3) th++;
    }
    if (sole % 2 != 0 && th == 0){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    int now = 0;
    bool pos = false;
    for (int i=0; i < n; i++){
        if (h[v[i]] == 1){
            if (now == 0) cout << "A";
            else cout << "B";
            now = 1-now;
            continue;
        }
        if ((h[v[i]] >= 3) && (!pos) && (sole % 2 != 0)){
            cout << "B";
            pos = true;
        }
        else cout << "A";
    }
}