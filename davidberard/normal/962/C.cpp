#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool valid(string s) {
    if(s.size() == 0) return false;
    return (s[0] != '0');
}

string build_string(string s, int bitmask) {
    string t;
    for(int i=0;i<s.size();++i) {
        if(bitmask & (1<<i)) {
            t += s[i];
        }
    }
    return t;
}

bool is_square(string s) {
    int x = atoi(s.c_str());
    return ((int) sqrt(x)* (int) sqrt(x) == x);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s; cin >> s;
    int bmsize = s.size();
    int best = bmsize+1;
    for(int i=0;i<(1<<bmsize);++i) {
        int amt = bmsize-__builtin_popcount(i);
        //cerr << "!! " << amt << endl;
        if(amt < best) {
            string t = build_string(s, i);
            if(valid(t) && is_square(t)) {
                best = amt;
            }
        }
    }
    cout << (best == bmsize+1 ? -1 : best) << endl;

    return 0;
}