#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int a=0,d=0;
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; ++i) {
        if(s[i]=='A') ++a;
        else ++d;
    }
    if(a == d) cout << "Friendship\n";
    else if(a > d) cout << "Anton\n";
    else cout << "Danik\n";
    return 0;
}