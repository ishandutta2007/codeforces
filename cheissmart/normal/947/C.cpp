#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[300005], p[300005], ans[300005];

struct trie{
	trie* x[2];
	int ct;
	trie() {
		x[0] = x[1] = nullptr;
		ct = 0;
	}
};

void add(trie* t, int x) {
	t->ct++;
	for(int i=30;i>=0;i--) {
		int c = x>>i&1;
		if(t->x[c] == nullptr) {
			t->x[c] = new trie();
		}
		t = t->x[c];
		t->ct++;
	}
}

void del(trie* t, int x, int i = 30) {
	if(t) t->ct--;
	if(i < 0)
		return;
	int c = x>>i&1;
	del(t->x[c], x, i-1);
	if(t->x[c]->ct == 0) {
		delete t->x[c];
		t->x[c] = nullptr;
	}
}

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	trie *t = new trie();
	for(int i=0;i<n;i++) {
		cin >> p[i];
		add(t, p[i]);
	}
	for(int i=0;i<n;i++) {
		trie* r = t;
		for(int j=30;j>=0;j--) {
			int c = a[i]>>j&1;
			if(r->x[c] != nullptr) {
				r = r->x[c];
			} else {
				ans[i] += 1<<j;
				r = r->x[c^1];
			}
		}
		del(t, ans[i]^a[i]);
	}

	for(int i=0;i<n;i++)
		cout << ans[i] << " \n"[i==n-1];
}