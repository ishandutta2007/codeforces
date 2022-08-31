#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    bool can = false;
    int T = s.size();
    for (int i=1; i <= (T-2)/2; i++){
        if (s[i] != s[i-1]) can = true;
    }
    if (!can){
        cout << "Impossible";
        return 0;
    }
    string k = s+s;
    for (int i=0; i < T; i++){
        bool can = true, eq = false;
        for (int j=0; j < T; j++){
            if (k[i+j] != k[i+T-1-j]) can = false;
            if (k[i+j] != k[j]) eq = true;
        }
        if (can && eq){
            cout << 1;
            return 0;
        }
    }
    cout << 2;
}