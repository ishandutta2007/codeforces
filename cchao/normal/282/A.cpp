#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; int a = 0;
    while(n--) {
        char s[10]; cin >> s;
        if(strchr(s, '+')) a++;
        else a--;
    }
    cout << a << endl;
    return 0;
}