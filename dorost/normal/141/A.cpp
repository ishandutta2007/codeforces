#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string a, b, s;
    cin >> a >> b >> s;
    a += b;
    sort(a.begin(), a.end());
    sort(s.begin(), s.end());
    cout << (a == s ? "YES" : "NO");
}