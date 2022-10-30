#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 240000;
char s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for (cin >> T; T; T--) {
        cin >> s;
        int cw = 0, cd = 0;
        int ma = 0, md = 0, mw = 0, ms = 0;
        int sa = 0, sd = 0, sw = 0, ss = 0;
        for(int i = 0; s[i]; i += 1){
            if(s[i] == 'W') cw += 1;
			if(s[i] == 'S') cw -= 1;
			if(s[i] == 'D') cd += 1;
			if(s[i] == 'A') cd -= 1;
            mw = max(mw, cw);
            ms = min(ms, cw);
            md = max(md, cd);
            ma = min(ma, cd);
            sw = max(sw, cw - ms);
            ss = max(ss, mw - cw);
            sd = max(sd, cd - ma);
            sa = max(sa, md - cd);
        }
        LL x1 = max(sw, ss);
        LL x2 = max(LL(sw or ss), x1 - !(sw == ss) );
        LL y1 = max(sd, sa);
        LL y2 = max(LL(sd or sa), y1 - !(sd == sa));
        cout << min((x1 + 1) * (y2 + 1), (x2 + 1) * (y1 + 1)) << endl;
    }
    return 0;
}