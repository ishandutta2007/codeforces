#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 111111;

struct Node {
	Node *next[26];
	int id;
	void clear() {
		memset(next, 0, sizeof(next));
	}
}mem[N], *root;
int used = 0;
int f[N][2];

Node *newNode() {
	mem[++used].clear();
	mem[used].id = used;
	return &mem[used];
}

int main() {
	root = newNode();
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		static char buffer[N];
		scanf("%s", buffer);
		Node *temp = root;
		for(int j = 0; buffer[j]; j++) {
			int idx = buffer[j] - 'a';
			if (temp->next[idx] == NULL) {
				temp->next[idx] = newNode();
			}
			temp = temp->next[idx];
		}
	}
	for(int i = used; i >= 1; i--) {
		bool flag = false;
		Node *temp = &mem[i];
		f[i][0] = f[i][1] = 0;
		for(int j = 0; j < 26; j++) {
			if (temp->next[j] != NULL) {
				flag = true;
				f[i][0] |= (f[temp->next[j]->id][0] ^ 1);
				f[i][1] |= (f[temp->next[j]->id][1] ^ 1);
			}
		}
		if (!flag) {
			f[i][0] = 0;
			f[i][1] = 1;
		}
	}
	if (f[1][0] == 0) {
		puts("Second");
	} else if (f[1][1] || (k & 1)) {
		puts("First");
	} else {
		puts("Second");
	}
	return 0;
}