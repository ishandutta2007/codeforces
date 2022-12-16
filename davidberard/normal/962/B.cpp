#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, rem[2]; cin >> N >> rem[0] >> rem[1];
    string s; cin >> s;
    int nxt = -1;
    int amt = 0;
    for(char c : s) {
        if(c == '*') {
            nxt = -1;
            continue;
        }
        if(nxt == -1) {
            nxt = (rem[0] > rem[1] ? 0 : 1);
        }
        if(rem[nxt] > 0) {
            amt += 1;
            rem[nxt]--;
        }
        nxt = (nxt+1)%2;
    }
    cout << amt << endl;
    return 0;
}