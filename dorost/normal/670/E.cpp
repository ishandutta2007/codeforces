/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 500001;
vector <int> v[N];

struct node {
	char val = 0;
	node* nxt = NULL;
	node* lst = NULL;
	node* p;
};

node* x[N];

struct llist {
	node* first = NULL, *last = NULL;
	int n = 0;
	node *a;
	void push_front(int x) {
		if (n == 0) {
			n++;
			a = new node();
			(*a).val = x;
			last = a;
			first = a;
			return;
		}
		n++;
		a = new node();
		(*first).lst = a;
		(*a).val = x;
		(*a).nxt = first;
		first = a;
	}
	void push_back(int x) {
		if (n == 0) {
			n++;
			a = new node();
			(*a).val = x;
			last = a;
			first = a;
			return;
		}
		n++;
		a = new node();
		(*last).nxt = a;
		(*a).val = x;
		(*a).lst = last;
		last = a;
	}
	void pop_back() {
		if (n == 0) {
			return;
		}
		if (n == 1) {
			first = last = NULL;
			n--;
			return;
		}
		n--;
		node* aa = (*last).lst;
		last = aa;
		(*last).nxt = NULL;
	}
	void pop_front() {
		if (n == 0) {
			return;
		}
		if (n == 1) {
			first = last = NULL;
			n--;
			return;
		}
		n--;
		node* aa = (*first).nxt;
		first = aa;
		(*first).lst = NULL;
	}
	int back() {
		return (*last).val;
	}
	int front() {
		return (*first).val;
	}
	int get(int i) {
		node* x = first;
		for (int j = 0; j < i; j++) {
			x = (*x).nxt;
		}
		return (*x).val;
	}
	void set(int i, int xx) {
		node* x = first;
		for (int j = 0; j < i; j++) {
			x = (*x).nxt;
		}
		(*x).val = xx;
	}
	void printall() {
		node* x = first;
		for (int j = 0; j < n; j++) {
			cout << (*x).val;
			x = (*x).nxt;
		}
		cout << '\n';
	}
	node* getA(int i) {
		node* x = first;
		for (int j = 0; j < i; j++) {
			x = (*x).nxt;
		}
		return x;
	}
	void erase(node* a) {
		if (n == 1) {
			first = last = NULL;
			n = 0;
			return;
		}
		if ((*a).lst == NULL) {
			pop_front();
			return;
		}
		if ((*a).nxt == NULL) {
			pop_back();
			return;
		}
		n--;
		node* l = (*a).lst, *nx = (*a).nxt;
		(*l).nxt = nx;
		(*nx).lst = l;
	}
	int size() {
		return n;
	}
	void insert(node* aa, int x) {
		if (n == 0) {
			push_back(x);
			n++;
			return;
		}
		if ((*aa).lst == NULL) {
			push_front(x);
			n++;
			return;
		}
		if ((*aa).nxt == NULL) {
			push_back(x);
			n++;
			return;
		}
		a = new node();
		(*a).val = x;
		node* l = (aa), *nx = (*aa).nxt;
		(*l).nxt = a;
		(*nx).lst = a;
		(*a).lst = l;
		(*a).nxt = nx;
		n++;
	}
	void eraseN(int i) {
		erase(getA(i));
	}
	void insertN(int i, int x) {
		insert(getA(i), x);
	}
};

int32_t main() {
	int n, m, p;
	cin >> n >> m >> p;
	string s, t;
	cin >> s >> t;
	int x1 = 0;
	llist l;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			v[x1].push_back(i);
			x1++;
		} else {
			x1--;
			v[x1].push_back(i);
		}
		l.push_back(s[i]);
	}
	x[0] = l.first;
	for (int i = 1; i < n; i++) {
		x[i] = x[i - 1] -> nxt;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < v[i].size(); j += 2) {
			x[v[i][j]] -> p = x[v[i][j + 1]];
			x[v[i][j + 1]] -> p = x[v[i][j]];
		}
	}
	node* w = x[p - 1];
	for (int i = 0; i < m; i++) {
		char c = t[i];
		if (c == 'L') {
			if (w -> lst == NULL)
				continue;
			w = w -> lst;
		}
		if (c == 'R') {
			if (w -> nxt == NULL)
				continue;
			w = w -> nxt;
		}
		node* nx;
		if (c == 'D') {
			node* g = w -> p;
			node* k = w;
			if (w -> val == '(') {
				if (g -> nxt == NULL) {
					nx = w -> lst;
				} else {
					nx = g -> nxt;
				}
				l.erase(k);
				while (k != g) {
					k = k -> nxt;
					l.erase(k);
				}
			} else {
				if (w -> nxt == NULL) {
					nx = g -> lst;
				} else {
					nx = w -> nxt;
				}
				l.erase(k);
				while (k != g) {
					k = k -> lst;
					l.erase(k);
				}
			}
			w = nx;
		}
	}
	l.printall();
}