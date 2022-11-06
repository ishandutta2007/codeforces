#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int mo = 998244353;

const int N = 2e5 + 5;

int T, n;
char s[N];

struct hwt {
    int fail[N], to[N][26], len[N], tot, last, n, la[N];
    void First() {
    	fo(i, 0, tot) {
			fail[i] = 0;
			memset(to[i], 0, sizeof to[i]);
			len[i] = 0;
		}
        tot = 1;
        len[1] = -1;
        fail[0] = 1;
        last = 0;
        s[0] = -1;
        n = 0;
    }
    int Getfail(int p) {
        while(s[n - len[p] - 1] != s[n]) p = fail[p];
        return p;
    }
    void add(char c) {
        n ++;
        int cur = Getfail(last);
        if(!to[cur][c]) {
            int p = ++ tot;
            len[p] = len[cur] + 2;
            fail[p] = to[Getfail(fail[cur])][c];
            to[cur][c] = p;
        }
        last = to[cur][c];
        la[n] = last;
    }
    int f[17][N];
    void build() {
		fo(i, 0, tot) f[0][i] = fail[i];
		fo(j, 1, 16) fo(i, 0, tot) f[j][i] = f[j - 1][f[j - 1][i]];
	}
	int solve(int x, int y) {
		x = la[x];
		if(len[x] <= y) return len[x];
		fd(j, 16, 0) if(len[f[j][x]] > y) x = f[j][x];
		return len[fail[x]];
	}
} s1, s2;

int al, ar, ans;

void gx(int bl, int br) {
	if(bl + n - br + 1 > ans) {
		ans = bl + n - br + 1;
		al = bl, ar = br;
	}
}

int main() {
//	freopen("a.in", "r", stdin); 
//	freopen("a.out", "w", stdout);
	for(scanf("%d", &T); T; T --) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		s1.First(); s2.First();
		
		fo(i, 1, n) {
			s1.add(s[i] - 'a');
		}
		reverse(s + 1, s + n + 1);
		fo(i, 1, n) {
			s2.add(s[i] - 'a');
		}
		reverse(s + 1, s + n + 1);
		
		s1.build(); s2.build();
		ans = 0, al = 0, ar = 0;
		
		int l = 0;
		while(2 * l <= n) {
			gx(l, n - l + 1);
			if(2 * l < n) {
				int x = s2.solve(n - (l + 1) + 1, n - 2 * l);
				gx(l + x, n - l + 1);
				x = s1.solve(n - l, n - 2 * l);
				gx(l, n - l + 1 - x);
			}
			if(s[l + 1] != s[n - l]) break;
			l ++;
		}
		fo(i, 1, al) pp("%c", s[i]);
		fo(i, ar, n) pp("%c", s[i]);
		hh;
//		pp("%d\n", ans);
	}
}