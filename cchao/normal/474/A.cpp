#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, n) for(int i = 0; i <= n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

const string s[] = {
"qwertyuiop",
"asdfghjkl;",
"zxcvbnm,./"
};

string t, d;
int main() {
    cin >> d >> t;
    int y = 0;
    if(d[0] == 'L') y = 1;
    if(d[0] == 'R') y = -1;
    for(int i = 0; i < t.length(); ++i) {
        char c = t[i];
        rep(j, 3) rep(k, s[j].length()) {
            if(s[j][k] == c) cout << s[j][k+y];
        }
    }
    cout << endl;
    return 0;
}