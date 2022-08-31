#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int h;
    cin >> h;
    vector<int> v(h+1);
    for (int i=0; i <= h; i++) cin >> v[i];
    bool last = false;
    vector<int> f, s;
    int L = 0;
    int S = 0;
    for (int i=0; i <= h; i++) S += v[i];
    for (int i=0; i <= h; i++){
        if (last && v[i] > 1){
            cout << "ambiguous" << endl;
            int C = L;
            for (int j=i; j <= h; j++){
                for (int k=0; k < v[j]; k++){
                    f.push_back(L);
                    s.push_back(L);
                }
                L += v[j];
            }
            s[C] = C-1;
            for (int j=0; j < S; j++) cout << f[j] << " ";
            cout << endl;
            for (int j=0; j < S; j++) cout << s[j] << " ";
            return 0;
        }
        else{
            if (v[i] > 1) last = true;
            else last = false;
            for (int j=0; j < v[i]; j++){
                f.push_back(L);
                s.push_back(L);
            }
            L += v[i];
        }
    }
    cout << "perfect" << endl;
    return 0;
}