#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    string sfx;
    int z = 0, o=0;
    bool seenTwo = false;
    for(auto& c : s) {
        if(c == '1') ++ o;
        if(c == '2') {
            sfx += '2';
            seenTwo = true;
        }
        if(c == '0') {
            if(seenTwo) {
                sfx+= '0';
            } else {
                ++z;
            }
        }
    }
    for(int j=0;j<z;++j) cout << '0';
    for(int j=0;j<o;++j) cout << '1';
    cout << sfx << "\n";
    return 0;
}