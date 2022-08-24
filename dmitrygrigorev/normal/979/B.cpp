#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    int A = 0, B = 0, C=0;
    map<char,int> ms;
    for (int i=0; i < a.size(); i++){
        ms[a[i]]++;
        A = max(A, ms[a[i]]);
    }
    ms.clear();
    for (int i=0; i < b.size(); i++){
        ms[b[i]]++;
        B = max(B, ms[b[i]]);
    }
    ms.clear();
    for (int i=0; i < c.size(); i++){
        ms[c[i]]++;
        C = max(C, ms[c[i]]);
    }
    ms.clear();
    if (a.size() - A > n) A += n;
    else{
        if (a.size() == A && n == 1) A = a.size() - 1;
        else A = a.size();
    }
    if (b.size() - B > n) B += n;
    else{
        if (b.size() == B && n == 1) B = b.size() - 1;
        else B = b.size();
    }
    if (c.size() - C > n) C += n;
    else{
        if (c.size() == C && n == 1) C = c.size() - 1;
        else C = c.size();
    }
    if (A > B && A > C){
        cout << "Kuro";
    }
    else if (B > A && B > C){
        cout << "Shiro";
    }
    else if (C > A && C > B){
        cout << "Katie";
    }
    else cout << "Draw";
}