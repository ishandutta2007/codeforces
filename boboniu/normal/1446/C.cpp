#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 7234567

struct Trie {
	Trie *son[2];
}node[maxN], *p=node;
int answer=0;

void dfs(Trie *q,int depth) {
	if (q->son[0]&&q->son[1]) depth+=1;
	answer=max(answer,depth);
	if (q->son[0]) dfs(q->son[0],depth);
	if (q->son[1]) dfs(q->son[1],depth);
}

int main() {
	int n;
	scanf("%d",&n);
	Trie *root=p++;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		Trie *q=root;
		for (int j=29;j>=0;j--) {
			int w=(x>>j)&1;
			if (!q->son[w]) q->son[w]=p++;
			q=q->son[w];
		}
	}
	dfs(root,0);
	printf("%d\n",n-answer-1);
}