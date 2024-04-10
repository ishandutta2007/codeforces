#include<bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int n; cin >> n;
    if(s == "AGC") puts(n >= 1200 ? "Yes" : "No");
    else if(s == "ARC") puts(n <= 2799 ? "Yes" : "No");
    else puts(n <= 1999 ? "Yes" : "No");
    return 0;
}