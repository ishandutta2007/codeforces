#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

const int M = 111111, N = 111111;

struct Node {
	vector<int> value;
	map<int, int> count;
	Node *next;
	
	void clear() {
		next = NULL;
		value.clear();
		count.clear();
	}
}mem[M];

int used;

Node *root;
int n, q, sn, a[N];

Node *newNode() {
	mem[++used].clear();
	return &mem[used];
}

void getVal(int a[], int n) {
	Node *temp = root->next;
	int m = 0;
	for(; temp != NULL; temp = temp->next) {
		for(int i = 0; i < (int)temp->value.size(); i++) {
			a[++m] = temp->value[i];
		}
	}
}

void construct(int a[], int n) {
	used = 1;
	root->next = newNode();
	Node *temp = root->next;
	for(int i = 1; i <= n; i++) {
		if (i % sn == 0) {
			temp->next = newNode();
			temp = temp->next;
		}
		temp->value.push_back(a[i]);
		temp->count[a[i]]++;
	}
}

int ask(int pos, int k) {
	int res = 0;
	Node *temp = root->next;
	for(; temp != NULL && pos; temp = temp->next) {
		if (temp->value.size() <= pos) {
			pos -= temp->value.size();
			res += temp->count[k];
		} else {
			for(int i = 0; i < pos; i++) {
				res += (temp->value[i] == k);
			}
			break;
		}
	}
	return res;
}


void shift(int l, int r) {
	Node *temp1 = root, *temp2 = root;
	int cur1 = 0, cur2 = 0;;
	for(; cur1 < l; ) {
		temp1 = temp1->next;
		cur1 += temp1->value.size();
	}
	for(; cur2 < r; ) {
		temp2 = temp2->next;
		cur2 += temp2->value.size();
	}
	
	int pos1 = l - (cur1 - temp1->value.size()) - 1;
	int pos2 = r - (cur2 - temp2->value.size()) - 1;
	int x = temp2->value[pos2];
	temp2->count[x]--;
	for(int i = pos2; i < (int)temp2->value.size() - 1; i++) {
		temp2->value[i] = temp2->value[i + 1];
	}
	temp2->value.pop_back();
	
	temp1->value.push_back(0);
	for(int i = (int)temp1->value.size() - 1; i > pos1; i--) {
		temp1->value[i] = temp1->value[i - 1];
	}
	temp1->value[pos1] = x;
	temp1->count[x]++;
}

int main() {
	used = 0;
	root = newNode();
	scanf("%d", &n);
	sn = 2 * (int)sqrt(n) + 10;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int lastAns = 0;
	construct(a, n);
	scanf("%d", &q);
	int cnt1 = 0;
	for(int i = 1; i <= q; i++) { 
		int type, l, r, k;
		scanf("%d %d %d", &type, &l, &r);
		l = ((l + lastAns - 1) % n) + 1;
		r = ((r + lastAns - 1) % n) + 1;
		if (l > r) {
			swap(l, r);
		}
		if (type == 1) {
			shift(l, r);
		} else {
			scanf("%d", &k);
			k = ((k + lastAns - 1) % n + 1);
			printf("%d\n", lastAns = ask(r, k) - ask(l - 1, k));
			if (++cnt1 == 5 * sn) {
				getVal(a, n);
				construct(a, n);
				//cerr << i << endl;
				cnt1 = 0;
			}
		}
	}
	return 0;
}