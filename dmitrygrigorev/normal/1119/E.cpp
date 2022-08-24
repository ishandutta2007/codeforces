#include <bits/stdc++.h>
#define int long long
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int nk = 0;
    int S=0;
    for (int i=0; i < n; i++){
        S += v[i];
        if (v[i] == 1) nk++;
        else{
            int T = v[i];
            while (T >= 2 && nk){
                T -= 2;
                nk--;
            }
            if (T==1) nk++;
        }
    }
    cout << (S-nk)/3;
}