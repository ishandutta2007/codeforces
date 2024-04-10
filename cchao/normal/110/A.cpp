#include <iostream>
#include <cstdio>
using namespace std;

bool f(int x) {
    if(x == 0) return false;
    while(x) {
        int t = x % 10;
        if(t != 4 && t != 7) return false;
        x /= 10;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.length(); ++i)
        if(s[i] == '4' || s[i] == '7') ans++;
    puts(f(ans) ? "YES" : "NO");
    return 0;
}