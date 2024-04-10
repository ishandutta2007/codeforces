#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair

#define rep(i, n) for(int i = 0; i < n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

const int maxn = 500000 + 10;
int n, a[maxn], nxt[maxn], lst[maxn];
bool vis[maxn]={};
priority_queue<pii> q;

void psh(int i) {
    q.push(mp(min(a[lst[i]], a[nxt[i]]), i));
}

void rm(int pos) {
    nxt[lst[pos]] = nxt[pos];
    lst[nxt[pos]] = lst[pos];
}

int main() {
    ri(n);
    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        ri(a[i]);
        nxt[i] = i+1;
        lst[i] = i-1;
    }
    nxt[0] = 1; lst[0] = n;
    lst[1] = nxt[n] = 0; a[0] = 0;

    for(int i = 1; i <= n; ) {
        while(i && a[i] <= min(a[lst[i]], a[nxt[i]])) {
            ans += min(a[lst[i]], a[nxt[i]]);
            rm(i);
            i = lst[i];
        }
        if(nxt[i] == 0) break;
        i = nxt[i];
    }

    for(int i = nxt[0]; i; i = nxt[i])
        psh(i);

    while(q.size()) {
        pii x = q.top(); q.pop();
        int val = x.fst, pos = x.snd;
        if(vis[pos]) continue;
        //cout << "pop " << val << ' '<< pos << endl;
        int check = min(a[lst[pos]], a[nxt[pos]]);
        if(check != val) {
            continue;
        }

        ans += val; vis[pos] = true;

        rm(pos);
        if(nxt[pos]) psh(nxt[pos]);
        if(lst[pos]) psh(lst[pos]);
        /*
        cout << "remove "  << a[pos] << " add " << val << ": ";
        for(int i = nxt[0]; i; i = nxt[i])
            cout << a[i] << ' ';
        cout << endl;
        */
    }

    cout << ans << endl;
    return 0;
}