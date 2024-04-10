#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

struct node {
	int nxt[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int id;
};

const int N = 70005;
char s[15];
char ans[N][15];
bool taken[N] = {0};
int iter = 0;

vector<node> tree;

int add(int j, int v) {
	if(v == -1) {
		tree.push_back(node());
		v = tree.size()-1;
		tree.back().id = iter;
	} else {
		if(tree[v].id != iter)
			tree[v].id = -1;
	}
	if(s[j] != 0) {
		int nv = add(j+1,tree[v].nxt[s[j]-'0']);
		tree[v].nxt[s[j]-'0'] = nv;
	}
	return v;
}

int best[N] = {};

void dfs1(int v, int d) {
	if(tree[v].id != -1)
		best[tree[v].id] = min(best[tree[v].id],d);
	for(int i = 0; i < 10; ++i) {
		if(tree[v].nxt[i] != -1) {
			dfs1(tree[v].nxt[i],d+1);
		}
	}
}


char stt[15];

void dfs2(int v, int d) {
	int q = tree[v].id;
	if(q != -1 && !taken[q] && best[q] == d) {
		for(int i = 0; i < d; ++i)
			ans[q][i] = stt[i];
		ans[q][d] = 0;
	}
	for(int i = 0; i < 10; ++i) {
		if(tree[v].nxt[i] != -1) {
			stt[d] = '0'+i;
			dfs2(tree[v].nxt[i],d+1);
		}
	}
}

int main() {
	int n;
	scanf("%d",&n);
	tree.resize(1);
	tree[0].id = -2;
	for(iter = 0; iter < n; ++iter) {
		scanf("%s",s);
		for(int j = 0; j < 9; ++j)
			add(j,0);
	}
	fill(best,best+n,1<<20);
	dfs1(0,0);
	dfs2(0,0);
	for(int i = 0; i < n; ++i) {
		printf("%s\n",ans[i]);
	}
}