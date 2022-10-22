#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, p;
    cin >> n >> p;
    int s[n], t[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    for (int i = 0; i < n; i++){
        cin >> t[i];
    }
    int a = 0, ta = 0, b = 0, tb = 0;
    for (int i = 0; i < n; i++){
        ta += t[i];
        a += max(0, s[i] - (ta * p));
    }
    for (int i = n - 1; i >= 0; i--){
        tb += t[i];
        b += max(0, s[i] - (tb * p));
    }
    if (a > b){
        cout << "Limak";
    }else if (a < b){
        cout << "Radewoosh";
    }else {
        cout << "Tie";
    }
}