#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];
long long ans = 0;

struct node {
	int nxt[2];
	int cnt[2];
};

struct trie {
	int root;
	int tc;
	node tree[maxn * 32];
	
	int insert(int x){
		int pos = root;
		for(int i=30;i>=0;i--){
			int p = ((x >> i) & 1);
			if(!tree[pos].nxt[p]){
				tree[pos].nxt[p] = ++tc;
			}
			tree[pos].cnt[p]++;
			pos = tree[pos].nxt[p];
		}
		return 0;
	}
	
	int remove(int x){
		int pos = root;
		for(int i=30;i>=0;i--){
			int p = ((x >> i) & 1);
			tree[pos].cnt[p]--;
			pos = tree[pos].nxt[p];
		}
		return 0;
	}
	
	int query(int pos, int x, int z){
		int ret = 0;
		for(int i=z;i>=0;i--){
			int p = ((x >> i) & 1);
			if(tree[pos].cnt[p]){
				pos = tree[pos].nxt[p];
				ret |= (p << i);
			}else{
				pos = tree[pos].nxt[!p];
				ret |= ((!p) << i);
			}
		}
		return ret;
	}
	
	int dfs(int pos, int x, int z, vector <int> &vec){
		if(x == 0){
			for(int i=1;i<=tree[pos].cnt[0];i++){
				vec.push_back(z);
			}
			for(int i=1;i<=tree[pos].cnt[1];i++){
				vec.push_back(z | 1);
			}
			return 0;
		}
		if(tree[pos].cnt[0]) dfs(tree[pos].nxt[0], x - 1, z, vec);
		if(tree[pos].cnt[1]) dfs(tree[pos].nxt[1], x - 1, z | (1 << x), vec);
		return 0;
	}
	
	int solve(int pos, int x){
		if(x == -1) return 0;
		if(x == 0){
			ans += (tree[pos].cnt[0] and tree[pos].cnt[1]);
			return 0;
		}
		
		if(tree[pos].cnt[0]) solve(tree[pos].nxt[0], x - 1);
		if(tree[pos].cnt[1]) solve(tree[pos].nxt[1], x - 1);
		
		if(tree[pos].cnt[0] and tree[pos].cnt[1]){
			if(tree[pos].cnt[0] > tree[pos].cnt[1]){
				vector <int> vec;
				dfs(tree[pos].nxt[1], x - 1, (1 << x), vec);
				long long tmp = 0x3f3f3f3f3f3f3f3f;
				for(auto i : vec){
					tmp = min(tmp, (long long)(query(tree[pos].nxt[0], i, x - 1) ^ i));
				}
				ans += tmp;
			}else{
				vector <int> vec;
				dfs(tree[pos].nxt[0], x - 1, 0, vec);
				long long tmp = 0x3f3f3f3f3f3f3f3f;
				for(auto i : vec){
					tmp = min(tmp, (long long)(query(tree[pos].nxt[1], i, x - 1) ^ i ^ (1 << x)));
				}
				ans += tmp;
			}
		}
		
		return 0;
	}
	
	int init(){
		root = 1;
		tc = 1;
		return 0;
	}
} A;

int main(){
	int i, j;
	int x, y, w;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	
	priority_queue <pair <int, int> > q;
	unordered_map <int, int> s;
	A.init();
	
	for(i=0;i<n;i++){
		A.insert(a[i]);
	}
	
	A.solve(A.root, 30);
	
	printf("%lld\n", ans);
	
	return 0;
}