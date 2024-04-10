#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, MOD = 1e9 + 123;
char s[MN], t[MN];
int bit[3][MN];
void update (int t, int i, int v) {
	for (++i;i<MN;i+=i&-i)
		bit[t][i] += v;
}
int query (int t, int i) {
	int ret = 0;
	for (++i;i;i^=i&-i)
		ret += bit[t][i];
	return ret;
}
void solve () {
	int n; scanf ("%d",&n);
	scanf ("%s",s);
	scanf ("%s",t);
	string ss = string(s), tt = string(t);
	sort(ss.begin(),ss.end());
	sort(tt.begin(),tt.end());
	if (ss != tt) {
		printf ("NO\n");
		return;
	}
	vector<int> posB;
	for (int i = 0; i < n; i++) {
		if (t[i] == 'b') posB.push_back(i);
	}
	for (int j = 0; j < 3; j++)
		for (int i = 0; i <= n+5; i++) bit[j][i] = 0;
	for (int i = 0; i < n; i++) {
		update(s[i]-'a', i, 1);
	}
	auto cntA = [&] (int l, int r) {
		return query(0,r) - query(0,l-1);
	};
	auto cntC = [&] (int l, int r) {
		return query(2,r) - query(2,l-1);
	};
	vector<array<int,2>> goLeft, goRight;
	int sofar = 0;
	for (int i = 0; i < n; i++) if (s[i] == 'b') {
		int togo = posB[sofar++];
		if (togo < i) goLeft.push_back({i,togo});
		else goRight.push_back({i,togo});
	}
	reverse(goRight.begin(),goRight.end());
	for (auto [i,togo] : goLeft) {
		if (cntA(togo,i-1) != i - togo) {
			printf ("NO\n");
			return;
		}
		update(s[i]-'a',i,-1);
		update(s[togo]-'a',togo,-1);
		swap(s[i],s[togo]);
		update(s[i]-'a',i,1);
		update(s[togo]-'a',togo,1);
	}
	for (auto [i,togo] : goRight) {
		if (cntC(i+1,togo) != togo - i) {
			printf ("NO\n");
			return;
		}
		update(s[i]-'a',i,-1);
		update(s[togo]-'a',togo,-1);
		swap(s[i],s[togo]);
		update(s[i]-'a',i,1);
		update(s[togo]-'a',togo,1);
	}
	for (int j = 0; j < n; j++) if (s[j] != t[j]) {
		printf ("NO\n");
		return;
	}
	printf ("YES\n");
}
int main () {
	int q; scanf ("%d",&q);
	while (q--) solve();
	return 0;
}
//x=3, y=2