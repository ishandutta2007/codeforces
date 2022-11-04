#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1005;

char s[N];
int n;

int d[N], d0;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int h = 0;
	fo(i, 1, n) fo(j, i + 1, n)	
		if(s[i] == '(' && s[j] == ')') {
			h = 1; break;
		}
	if(!h) {
		pp("0\n");
		return 0;
	}
	pp("1\n");
	int t = 0;
	fo(i, 1, n) {
		t += (s[i] == '(');
		int t2 = 0;
		fo(j, i + 1, n) t2 += (s[j] == ')');
		if(t >= t2) {
			t = min(t, t2);
			t2 = t;
			pp("%d\n", t * 2);
			fo(j, 1, n) {
				if(s[j] == '(') {
					pp("%d ", j);
					if(-- t == 0) break;
				}
			}
			fd(j, n, i + 1) {
				if(s[j] == ')') {
					d[++ d0] = j;
					if(-- t2 == 0) break;
				}
			}
			fd(j, d0, 1) pp("%d ", d[j]); hh;
			return 0;
		}
	}
}