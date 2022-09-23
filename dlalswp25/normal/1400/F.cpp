#include <bits/stdc++.h>

using namespace std;

int tid;

struct Trie {
    Trie *go[10];
    Trie *fail;
    bool output;
    int id;
    
    Trie() {
        fill(go, go + 10, nullptr);
        output = false;
        id = ++tid;
    }

    void insert(const char* key) {
        if(*key == '\0') {
            output = true;
            return;
        }
        int nxt = *key - '0';
        if(!go[nxt]) {
            go[nxt] = new Trie;
        }
        go[nxt] -> insert(key + 1);
    }
};

int N, X;
char S[1010];
char buf[30];
int sum[30];

Trie* root = new Trie;

int D[1010][5050];

void make_str(int n, int s) {
	if(X < s) return;

	for(int i = 0; i < n; i++) {
		if(sum[n] - sum[i] < X && X % (sum[n] - sum[i]) == 0) return;
	}

	if(X == s) {
		buf[n + 1] = 0;
		// printf("%s\n", buf + 1);
		root -> insert(buf + 1);
		return;
	}

	for(int i = 1; i <= 9; i++) {
		buf[n + 1] = i + '0';
		sum[n + 1] = sum[n] + i;
		make_str(n + 1, s + i);
	}
}

void gen() {
    queue<Trie*> q;
    root -> fail = root;
    q.push(root);

    while(q.size()) {
		Trie *cur = q.front();
		q.pop();

		for(int i = 1; i <= 9; i++) {
			Trie *nxt = cur -> go[i];
			if(!nxt) continue;
 
			if(cur == root) nxt -> fail = root;
			else {
				Trie *dest = cur -> fail;
				while(dest != root && !dest -> go[i]) dest = dest->fail;

				if(dest -> go[i]) dest = dest -> go[i];
				nxt -> fail = dest;
			}

			if(nxt -> fail -> output) nxt -> output = true;

 			q.push(nxt);
		}
	}
}

int f(int n, Trie* p) {
	int x = p -> id;
	// printf("%d %d\n", n, x);
	if(D[n][x] != -1) return D[n][x];
	if(n > N) return 0;
	D[n][x] = f(n + 1, p) + 1;

	Trie *nxt = p;
	int m = S[n] - '0';

	while(nxt != root && !nxt -> go[m]) {
		nxt = nxt -> fail;
	}

	if(nxt -> go[m]) {
		if(!nxt -> go[m] -> output) D[n][x] = min(D[n][x], f(n + 1, nxt -> go[m]));
	}
	else D[n][x] = min(D[n][x], f(n + 1, root));
	return D[n][x];
}

int main() {
	scanf("%s", S + 1);
	N = strlen(S + 1);
	scanf("%d", &X);

	make_str(0, 0);
	gen();

	// printf("%d\n", tid);
	for(int i = 0; i < 1010; i++) for(int j = 0; j < 5050; j++) D[i][j] = -1;
	printf("%d\n", f(1, root));

	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= tid; j++) {
	// 		printf("%d ", D[i][j]);
	// 	}
	// 	puts("");
	// }

	return 0;
}