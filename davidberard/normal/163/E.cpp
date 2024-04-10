#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl "\n"
#endif

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 1001000;
int cc = 1;

int bt[NMAX+1];

struct bit {
  int n;
  bit() {}
  bit(int sz) : n(sz+1) {}
  inline int lobit(int i) {
    return i&-i;
  }
  inline void assign(int i, int x) {
    for(; i<n; i+=lobit(i)) {
      bt[i] += x;
    }
  }
  inline int query(int i) {
    int ans = 0;
    for(; i; i-=lobit(i)) {
      ans += bt[i];
    }
    return ans;
  }
};

struct node { int l[26], nxt[26], failure, suffix; int index;
  node(){}
};

node no[NMAX];
bit b(NMAX);
vector<int> ch[NMAX];
int in[NMAX], out[NMAX];
int dd;

int ninsert(int ni, const string& s, int id, int i=0) {
  if(i == s.size()) { no[ni].index = id; return ni; }
  if(no[ni].l[s[i]-'a'] == 0) {
    no[ni].l[s[i]-'a'] = ++cc;
  }
  return ninsert(no[ni].l[s[i]-'a'], s, id, i+1);
}

void build_links(int rt) { queue<int> que; que.push(rt);
  while (!que.empty()) { int pi = que.front(); que.pop();
    for (int i=0; i<26; ++i) { if (no[pi].l[i]) no[pi].nxt[i] = no[pi].l[i]; else {
        int q = no[pi].failure; while (q && !no[q].nxt[i]) q = no[q].failure;
        no[pi].nxt[i] = q ? no[q].nxt[i] : rt; } } /*compute nxt[] state per char*/
    for (int i=0; i<26; ++i) if (no[pi].l[i]) { int q = no[pi].failure;
      while (q && !no[q].l[i]) q = no[q].failure;
      if (q) { no[no[pi].l[i]].failure = no[q].l[i];
        no[no[pi].l[i]].suffix = (no[no[q].l[i]].index ? no[q].l[i] : no[no[q].l[i]].suffix);
      } else no[no[pi].l[i]].failure = no[no[pi].l[i]].suffix = rt;
      ch[no[no[pi].l[i]].suffix].push_back(no[pi].l[i]);
    que.push(no[pi].l[i]); } /*compute fail ptr*/ } }

void dfs(int u) {
    in[u] = ++dd;
    for(auto& v : ch[u]) {
        dfs(v);
    }
    out[u] = dd+1;
}

ll get_matches(string &s, int rt, unsigned int start) {
  ll ans=0; int cur = rt;
  for (auto i=start; i < s.size(); i++) { int c=s[i]-'a';
    cur=no[cur].nxt[c]; //shortcut traversal
    //assert(in[cur]);
    ans += b.query(in[cur]);
  }
  return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> vn(K+1);
	vector<string> s(K+1);
	for(int i=1;i<=K;++i)
	{
		cin >> s[i];
		vn[i] = ninsert(1, s[i], i, 0);
	}
	build_links(1);
    dfs(1);
    for(int i=1;i<=K;++i) {
        b.assign(in[vn[i]], 1);
        b.assign(out[vn[i]], -1);
    }
	ll ans = 0;
	for(int i=0;i<N;++i)
	{
		string q;
		cin >> q;
		if(q[0] == '?') {
			ans = get_matches(q, 1, 1);
			cout << ans << endl;
		} else if (q[0] == '+') {
			int n = atoi(q.c_str()+1);
            if(!no[vn[n]].index) {
                b.assign(in[vn[n]], 1);
                b.assign(out[vn[n]], -1);
                no[vn[n]].index = n;
            }
		} else if (q[0] == '-') {
			int n = atoi(q.c_str()+1);
            if(no[vn[n]].index) {
                b.assign(in[vn[n]], -1);
                b.assign(out[vn[n]], 1);
                no[vn[n]].index = 0;
            }
		} //else { assert(false); }
	}

	return 0;
}