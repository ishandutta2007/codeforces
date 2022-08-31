#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string t;
    cin >> s >> t;
    for (int i=0; i < s.size(); i++){
        if (s[i] == 'C') s[i] = 'B';
    }
    for (int i=0; i<t.size(); i++){
        if (t[i] == 'C') t[i] = 'B';
    }
    int n = s.size(), m = t.size();
    int prefs[n+1], preft[m+1];
    prefs[0] = 0, preft[0] = 0;
    for (int i=0; i < n; i++){
        prefs[i+1] = prefs[i] + (s[i] =='B');
    }
    for (int i=0; i < m; i++){
        preft[i+1] = preft[i] + (t[i] == 'B');
    }
    int ls[n+1], lt[m+1];
    ls[0] = 0, lt[0] = 0;
    for (int i=0; i < n; i++){
        if (s[i] == 'B') ls[i+1] = 0;
        else ls[i+1] = ls[i] + 1;
    }
    for (int i=0; i < m; i++){
        if (t[i] == 'B') lt[i+1] = 0;
        else lt[i+1] = lt[i] + 1;
    }
    int q;
    cin >> q;
    for (int i=0; i < q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int F = prefs[b+1] - prefs[a];
        int S = preft[d+1] - preft[c];
        if (F%2 != S%2){
            cout << 0;
            continue;
        }
        if (F > S){
            cout << 0;
            continue;
        }
        int A = ls[b+1], B = lt[d+1];
        A = min(A, b-a+1);
        B = min(B, d-c+1);
        if (A<B){
            cout << 0;
            continue;
        }
        if (F==0){
            if (S!=0){
                if (A==B) cout << 0;
                else cout << 1;
            }
            else{
                if (A%3==B%3) cout << 1;
                else cout << 0;
            }
            continue;
        }
        else if (A%3==B%3) cout << 1;
        else {
            F += 2;
            if (F > S) cout << 0;
            else cout << 1;
        }
    }
    return 0;
}