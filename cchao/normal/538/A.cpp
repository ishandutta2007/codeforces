#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    string s; cin >> s;

    rep(i, s.size()) {
        rep(j, i + 1) {
            string t = "";
            rep(k, s.size()) {
                if(k < j || k > i) t += s[k];
            }
            if(t == "CODEFORCES") {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");

    return 0;
}