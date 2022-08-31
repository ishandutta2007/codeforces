#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    vector<int> a(n);
    int cnt = n-1;
    while (v.size() > 0){
        for (int i=1; i < v.size(); i++){
            if (abs(v[i] - v[i-1]) >= 2){
                cout << "NO" << endl;
                return 0;
            }
        }
        int mx = -1, wh = -1;
        for (int i=0; i < v.size(); i++){
            if (v[i] > mx){
                mx = v[i], wh=i;
            }
        }
        vector<int> nv;
        for (int i=0; i < v.size(); i++) if (i!=wh) nv.push_back(v[i]);
        v = nv;
        a[cnt] = mx;
        cnt--;
    }
    for (int i=1; i < a.size(); i++){
        if (abs(v[i] - v[i-1]) >= 2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}