// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

namespace SAM {
	constexpr int MAXN = 100005;
	constexpr int MAXT = 177;
	struct state {
		int len, lnk, fpo;
		map<int, int> nxt;
	} st[MAXN*2];
	int sz, last;
	int mknode(int fro = -1) {
		int nd = sz++;
		if(fro != -1) {
			st[nd].nxt = st[fro].nxt;
			st[nd].lnk = st[fro].lnk;
			st[nd].fpo = st[fro].fpo;
		}
		return nd;
	}
	void init() {
		sz = last = 0;
		mknode(); st[0].len = 0, st[0].lnk = -1;
	}
	void ext(int c) {
		int cur = mknode();
		st[cur].len = st[last].len+1;
		st[cur].fpo = st[cur].len-1;
		int p = last;
		while(p != -1 && !st[p].nxt.count(c)) st[p].nxt[c] = cur, p = st[p].lnk;
		if(p == -1) st[cur].lnk = 0;
		else {
			int q = st[p].nxt[c];
			if(st[p].len + 1 == st[q].len) st[cur].lnk = q;
			else {
				int cl = mknode(q); 
				st[cl].len = st[p].len + 1; st[cur].lnk = st[q].lnk = cl;
				while(p != -1 && st[p].nxt[c] == q) st[p].nxt[c] = cl, p = st[p].lnk;
			}
		}
		last = cur;
	}
	vector<int> revlnk[MAXN*2];
	int lpo[MAXN*2];
	int dfs(int p) {
		lpo[p] = st[p].fpo;
		for(int& v:revlnk[p]) lpo[p] = max(lpo[p], dfs(v));
		return lpo[p];
	}
	void makelpo() {
		rep1(i, sz-1) revlnk[st[i].lnk].pb(i);
		dfs(0);
	}
}

struct samstate {
	int curnode;
	int curlen;
	queue<char> q;
	samstate() : curnode(0), curlen(0) { }
	bool canupdate(char c) { return SAM::st[curnode].nxt.count(c-'A'); }
	void forceupdate(char c) { curnode = SAM::st[curnode].nxt[c-'A']; }
	void maintainq() {
		while(q.size() && canupdate(q.front())) {
			forceupdate(q.front());
			curlen++;
			q.pop();
		}
	}
	void pop() {
		int b = SAM::st[curnode].lnk;
		if(SAM::st[b].len == curlen-1) curnode = b;
		curlen--;
		maintainq();
	}
	void push(char c) {
		q.push(c);
		maintainq();
	}
	int firstoccur() {
		if(q.size()) return 1000000;
		return SAM::st[curnode].fpo;
	}
	int lastoccur() {
		if(q.size()) return -1;
		return SAM::lpo[curnode];
	}
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string pp; cin >> pp;
    SAM::init();
    for(char&c:pp) SAM::ext(c-'A');
    SAM::makelpo();
    int n, ans = 0; cin >> n;
    rep(i, n) {
    	string s; cin >> s;
    	samstate p1, p2; for(char& c:s) p2.push(c);
    	int nt = s.length();
    	rep(i, (int)s.length()-1) {
    		p1.push(s[i]);
    		p2.pop(); nt--;
    		if(p1.firstoccur() <= p2.lastoccur()-nt) { ans++; break; }
    	}
    }
    cout << ans << endl;
}