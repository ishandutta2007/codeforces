#include <bits/stdc++.h>
using namespace std;

const int N = 660000;
int M, e[22], lo[22], hi[22], n;
long long tot;
int rgt, ans;
int f(char c) {
	if (c < 'a') return 25 + c - 'A';
	return c - 'a';
}
struct Node {
	int l, r, pardp, cnt[12];
	Node *par, *sLink;
	Node* chd[38];
	Node() {
		l = r = pardp = 0;
		memset(cnt, 0, sizeof cnt);
		par = sLink = NULL;
		for (int i = 0; i < 38; i++) chd[i] = NULL;
	}
	int len() {
		return r - l;
	}
	int depth() {
		return pardp + len();
	}
	bool inEdge(int pos) {
		return pos >= pardp && pos < depth();
	}
	void setEdge(Node *child, int l, int r, char *S) {
		child->par = this;
		child->pardp = depth();
		chd[f(S[l])] = child;
		child->l = l, child->r = r;
	}
};
struct STree {
	Node *root, *needSLink, *cur;
	int jj, m, size;
	bool needWalk;
	vector<Node> nodes;
	char *S;
	STree(char *str) {
		m = strlen(str);
		S = str;
		nodes.reserve(m * 2 + 10);
		jj = 1, size = 0;
		root = newNode();
		cur = newNode();
		root->setEdge(cur, 0, m, S);//  extend(-1) . 
		needSLink = NULL;
		needWalk = true;
		for (int i = 0; i < m - 1; i++) extend(i);
	}
	Node *newNode() {
		nodes.push_back(Node());
		return &nodes[size++];
	}
	Node *walk_down(Node *c, int j, int i) {
		if (i - j + 1 > 0) {
			for (int h = j + c->depth(); !c->inEdge(i - j); h += c->len())
				c = c->chd[f(S[h])];
		}
		return c;
	}
	void addSLink(Node *c) {
		if (needSLink) needSLink->sLink = c;
		needSLink = NULL;
	}
	void extend(int i) {
		char c = S[i + 1];
		Node *leaf, *split;
		int k, pos;
		for (; jj <= i + 1; jj++) {
			if (needWalk) {
				if (!cur->sLink && cur->par) cur = cur->par;
				cur = (cur->sLink) ? cur->sLink : root;
				cur = walk_down(cur, jj, i);
			}
			needWalk = true;
			k = i + 1 - jj; 
			if (cur->depth() == k) {  
				addSLink(cur);
				if (cur->chd[f(c)]) {// 3    
					cur = cur->chd[f(c)];
					needWalk = false;
					break;
				}
				else { // 1  2   : 
					leaf = newNode();
					cur->setEdge(leaf, i + 1, m, S);
				}
			}
			else {
				pos = cur->l + k - cur->pardp; //pos cur i  
				if (S[pos] == c) {// 3    
					addSLink(cur);
					// cur sLink    cur  
					//   1   . 
					needWalk = false;
					break;
				}
				else {// 2    
					leaf = newNode();
					split = newNode();
					cur->par->setEdge(split, cur->l, pos, S);
					split->setEdge(cur, pos, cur->r, S);
					split->setEdge(leaf, i + 1, m, S); 
					addSLink(split);
					if (split->depth() == 1) split->sLink = root;
					else needSLink = split;
					cur = split;
				}
			}
		}
	}
	void calc(Node *par) {
		for (int i = 0; i < 37; i++) {
			Node *son = par->chd[i];
			if (son == NULL) continue;
			calc(son);
			for (int j = 1; j <= n + 1; j++) {
				par->cnt[j] += son->cnt[j];
				if (son->l <= e[j] && son->r > e[j]) par->cnt[j]++;
			}
		}
		if (par->l <= e[1] && par->r > e[1]) {
			int add = e[1] - par->l;
			for (int j = 1; j <= n + 1; j++) if (par->l <= e[j] && par->r > e[j]) par->cnt[j]++;
			bool ok = true;
			for (int j = 2; j <= n + 1; j++) {
				int x = par->cnt[j] - par->cnt[j - 1];
				ok &= (x >= lo[j - 1] && x <= hi[j - 1]);
			}
			if (ok) tot += add;
			for (int j = 1; j <= n + 1; j++) if (par->l <= e[j] && par->r > e[j]) par->cnt[j]--;
			return;
		}
		if (!par->cnt[1]) return;
		bool ok = true;
		for (int j = 2; j <= n + 1; j++) {
			int x = par->cnt[j] - par->cnt[j - 1];
			ok &= (x >= lo[j - 1] && x <= hi[j - 1]);
		}
		if (ok) tot += par->len();
	}
};
char str[N], s[N];
int main() {
	scanf("%s", str);
	scanf("%d", &n);
	e[1] = strlen(str);
	str[e[1]] = 'A' + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		strcat(str, s);
		scanf("%d%d", lo + i, hi + i);
		e[i + 1] = strlen(str);
		str[e[i + 1]] = 'A' + i + 1;
	}
	STree tree(str);
	tree.calc(tree.root);
	printf("%lld\n", tot);
	return 0;
}