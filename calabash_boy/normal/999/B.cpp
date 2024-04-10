#include<bits/stdc++.h>
using namespace std;
int n;
string s;
#define rep(x,l,r) for (int x = l;x<r;x++)
int main() {
    cin >> n >> s;
    for (int i = 2; i <= n; i++) {
        if (n%i == 0) {
            for (int j = 0; j < i/2; j++) {
                char t = s[j];
                s[j] = s[i - j-1];
                s[i - j-1] = t;
            }
        }
    }
    cout << s << endl;
    return 0;
}