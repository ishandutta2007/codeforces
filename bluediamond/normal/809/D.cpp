#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;


const int SKIP_VALUE = -1;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = (int)1e9 + 7;
vector<int> priorities(1200000 + 7);


struct Node {
	int dim = 1;
	int priority;
	int store;
	int lazy = 0;
	Node* lft = nullptr;
	Node* rgh = nullptr;
	Node(int value) :
		store(value) {
		priority = priorities.back();
		priorities.pop_back();
	}
	~Node() {
		if (lft) delete lft;
		if (rgh) delete rgh;
	}
};

void push(Node* root) {
	if (root && root->lazy) {
		root->store += root->lazy;
		if (root->lft) root->lft->lazy += root->lazy;
		if (root->rgh) root->rgh->lazy += root->lazy;
		root->lazy = 0;
	}
}

bool inner_print(Node* root) {
	assert(root);
	assert(root->dim > 0);
	push(root);

	if (root->lft) {
		if (inner_print(root->lft)) return 1;
	}
	if (root->store != SKIP_VALUE) {
		if (root->store == INF) {
			cout << "inf\n";
			return 1;
		}
		cout << root->store << " ";
	}
	if (root->rgh) return inner_print(root->rgh);
	return 0;
}


void build(Node* lft, Node* root, Node* rgh) {
	push(root);
	push(lft);
	push(rgh);
	root->lft = lft;
	root->rgh = rgh;
	root->dim = 1;
	if (lft) root->dim += lft->dim;
	if (rgh) root->dim += rgh->dim;
}

void changeVal(Node* root, int pos, int nw) {
	push(root);
	assert(root);
	assert(root->dim > 0);
	assert(1 <= pos && pos <= root->dim);

	int current_pos = (root->lft ? root->lft->dim : 0) + 1;

	if (pos == current_pos) {
		root->store = nw;
		return;
	}

	if (pos < current_pos) {
		changeVal(root->lft, pos, nw);
	}
	else {
		changeVal(root->rgh, pos - current_pos, nw);
	}
}

int access(Node* root, int pos) {
	push(root);
	assert(root);
	assert(root->dim > 0);
	assert(1 <= pos && pos <= root->dim);

	int current_pos = (root->lft ? root->lft->dim : 0) + 1;

	if (pos == current_pos) {
		return root->store;
	}

	if (pos < current_pos) {
		return access(root->lft, pos);
	}
	else {
		return access(root->rgh, pos - current_pos);
	}
}

int fnd(Node* root, int val) {
	push(root);
	assert(root);
	assert(root->dim > 0);

	int current_pos = (root->lft ? root->lft->dim : 0) + 1;

	if (root->store >= val) {
		int x = -1;
		if (root->lft) x = fnd(root->lft, val);
		if (x == -1) x = current_pos;
		return x;
	}
	int x = -1;
	if (root->rgh) x = fnd(root->rgh, val);
	if (x != -1) x += current_pos;
	return x;
}

pair<Node*, Node*> split(Node* root, int pos) {
	push(root);
	if (!root) {
		assert(pos == 0);
		return make_pair(nullptr, nullptr);
	}
	assert(0 <= pos && pos <= root->dim);

	if (pos == 0) {
		return make_pair(nullptr, root);
	}

	if (pos == root->dim) {
		return make_pair(root, nullptr);
	}

	int dim_lft = (root->lft ? root->lft->dim : 0);
	int dim_rgh = (root->rgh ? root->rgh->dim : 0);

	if (pos <= dim_lft) {
		pair<Node*, Node*> pr = split(root->lft, pos);
		build(pr.second, root, root->rgh);
		return make_pair(pr.first, root);
	}
	else {
		pair<Node*, Node*> pr = split(root->rgh, pos - dim_lft - 1);
		build(root->lft, root, pr.first);
		return make_pair(root, pr.second);
	}
}

Node* join(Node* a, Node* b) {
	push(a);
	push(b);
	if (!a) return b;
	if (!b) return a;

	if (a->priority > b->priority) {
		build(a->lft, a, join(a->rgh, b));
		return a;
	}
	else {
		build(join(a, b->lft), b, b->rgh);
		return b;
	}
}

Node* ins(Node* root, int value, int pos) {
	push(root);


	Node* guy = new Node(value);
	pair<Node*, Node*> pr = split(root, pos);

	return join(join(pr.first, guy), pr.second);
}



struct Segment {
	int l, r;
};

const int N = (int)6e5 + 7;

int n;
int y;
Segment s[N];

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	iota(priorities.begin(), priorities.end(), 0);
	shuffle(priorities.begin(), priorities.end(), rng);
	Node* root = new Node(0);

	for (int i = 1; i < N; i++) {
		root = ins(root, INF, i);
	}

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].l >> s[i].r;
	}

	for (int i = 1; i <= n; i++) {
		int l, r;
		l = s[i].l;
		r = s[i].r;

		{ // first part
			int st, dr;
			st = fnd(root, l + 1) - 1;
			dr = fnd(root, r + 1) - 2;
			if (st <= dr) {
				{
					st++, dr++;

					{
						int delpos = dr + 1;
						auto p1 = split(root, delpos);
						auto p2 = split(p1.first, delpos - 1);
						root = join(p2.first, p1.second);
					}

					{
						int e = access(root, st);
						root = ins(root, e, st - 1);
					}

					st--, dr--;
				}

				{
					st += 2;
					dr += 2;
					auto p1 = split(root, dr);
					auto p2 = split(p1.first, st - 1);
					p2.second->lazy++;
					root = join(join(p2.first, p2.second), p1.second);
				}

			}
		}

		{ // second part
			int sol = fnd(root, l + 1) - 2;


			if (sol != -1) {
				changeVal(root, sol + 2, l + 1);
			}
		}
	}


	int sol = 1;
	while (access(root, sol + 1) != INF) sol++;
	cout << sol - 1 << "\n";
}