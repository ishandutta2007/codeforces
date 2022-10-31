#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[110]; cin >> s;
    sort(s, s+strlen(s));
    
    for(int i = 0; s[i]; ++i) {
        if(s[i] != '+')
            cout << s[i] << (s[i+1]?'+' : '\n');
    }
    
    return 0;
}