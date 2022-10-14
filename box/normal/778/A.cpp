#include <iostream>
#include <string>
using namespace std;

int seq[200005];
string st, targ;

bool test(int n) {
    string s = st;
    for(int i=0; i<n; i++) s[seq[i]] = '*';
    int ind = 0;
    for(char c:s) {
        if(c == targ[ind]) {
            ind++;
            if(ind == targ.length()) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> st >> targ;
    for(int i=0; i<st.length(); i++) {
        cin >> seq[i];
        seq[i]--;
    }
    int l = 0, r = st.length(), ans = -1;
    while(l <= r) {
        int m = (l+r)/2;
        if(test(m)) {
            ans = m;
            l = m+1;
        } else r = m-1;
    }
    cout << ans << endl;
}