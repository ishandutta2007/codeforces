#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 1e9 + 7;

int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

int to(char c) {
	if(c == 'L') return 0;
	else if(c == 'R') return 1;
	else if(c == 'U') return 2;
	else return 3;
}

signed main()
{
	IO_OP;

	int n, h, w;
	string s;
	cin >> n >> h >> w >> s;
	V<pi> evt1, evt2;
	{
		int mnx = 1, mxx = h, mny = 1, mxy = w;
		int cur_mnx = 1, cur_mxx = h, cur_mny = 1, cur_mxy = w;
		for(int i = 0; i < n * 2 && mnx <= mxx && mny <= mxy; i++) {
			int which = to(s[i % n]);
			if(dx[which] == 1) cur_mxx--, cur_mnx--;
			if(dx[which] == -1) cur_mnx++, cur_mxx++;
			if(dy[which] == 1) cur_mxy--, cur_mny--;
			if(dy[which] == -1) cur_mny++, cur_mxy++;
			if(cur_mnx > mnx) {
				if(i < n) evt1.EB(which, i + 1);
				else evt2.EB(which, i + 1);
				mnx = cur_mnx;
			}
			if(cur_mxx < mxx) {
				if(i < n) evt1.EB(which, i + 1);
				else evt2.EB(which, i + 1);
				mxx = cur_mxx;
			}
			if(cur_mny > mny) {
				if(i < n) evt1.EB(which, i + 1);
				else evt2.EB(which, i + 1);
				mny = cur_mny;
			}
			if(cur_mxy < mxy) {
				if(i < n) evt1.EB(which, i + 1);
				else evt2.EB(which, i + 1);
				mxy = cur_mxy;
			}
		}
	}
	auto add = [&](int&a, int b){
		a += b;
		if(a >= M) a -= M;
	};
	int ans = 0;
	{
		int mnx = 1, mxx = h, mny = 1, mxy = w;
		for(pi e:evt1) {
			int which = e.F;
			if(dx[which] == 1) mxx--, add(ans, (ll) (mxy - mny + 1) * e.S % M);
			if(dx[which] == -1) mnx++, add(ans, (ll) (mxy - mny + 1) * e.S % M);
			if(dy[which] == 1) mxy--, add(ans, (ll) (mxx - mnx + 1) * e.S % M);
			if(dy[which] == -1) mny++, add(ans, (ll) (mxx - mnx + 1) * e.S % M);
		}
		if(evt2.size()) {
			int i = -1, more = 0;
			while(mnx <= mxx && mny <= mxy) {
				if(++i == evt2.size()) i -= evt2.size(), add(more, n);
				pi e = evt2[i];
				int which = e.F;
				if(dx[which] == 1) mxx--, add(ans, (ll) (mxy - mny + 1) * (e.S + more) % M);
				if(dx[which] == -1) mnx++, add(ans, (ll) (mxy - mny + 1) * (e.S + more) % M);
				if(dy[which] == 1) mxy--, add(ans, (ll) (mxx - mnx + 1) * (e.S + more) % M);
				if(dy[which] == -1) mny++, add(ans, (ll) (mxx - mnx + 1) * (e.S + more) % M);
			}
		}
		if(mnx <= mxx && mny <= mxy) return cout << -1 << endl, 0;
	}
	cout << ans << endl;
	
}