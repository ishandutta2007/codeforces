#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    bool d = 0;
    int t;
    cin >> t;
    string p,h;
    vector <char> a,b;
    for (int l = 0; l < t; l++){
        string ans = "NO";
        cin >> p >> h;
        int n = h.size();
        int m = p.size();
        for (int i = 0; i <= n - m; i++){
            a.clear();
            b.clear();
            for (int k = i;k < m + i; k++){
                a.push_back(h[k]);
            }
            for (int j = 0; j < m; j++){
                b.push_back(p[j]);
            }
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            bool f = true;
            for (int j = 0; j < a.size(); j++){
                if (a[j] != b[j]){
                    f = false;
                    break;
                }
            }
            if (f) {
                ans = "YES";
            }
            }
            cout << ans << endl;
        }
}