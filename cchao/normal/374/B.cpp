#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fst first
#define snd second
#define mp(a,b) make_pair(a, b)

#define RD(x) scanf("%d", &x)
#define RDD(x, y) scanf("%d%d", &x, &y)
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define CLR(A, V) memset(A, V, sizeof A)
#define PD(x) printf("%d\n", x)

char s[100010];
int main() {
    scanf("%s", s);

    ll ans = 1;
    for(int i = 1; s[i]; ++i) {
        int l = 1;
        while(s[i] && (s[i] + s[i-1] - '0' - '0' == 9)) ++i, ++l;
        if(l&1) ans = ans * ((l + 1) / 2);
    }
    cout << ans << endl;
    return 0;
}