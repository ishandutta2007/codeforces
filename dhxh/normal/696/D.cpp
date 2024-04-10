#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;

int n;
long long l;

int a[maxn];
string str[maxn];

struct matrix {
	long long f[maxn][maxn];
	
	matrix(){memset(f, 0xc0, sizeof(f));}
};

matrix E, F, G;

matrix mul(matrix &A, matrix &B){
	matrix ret;
	
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			for(int k=0;k<maxn;k++){
				ret.f[i][j] = max(ret.f[i][j], A.f[i][k] + B.f[k][j]);
			}
		}
	}
	
	return ret;
}

matrix qpow(matrix b, long long x){
	matrix ret = E;
	
	while(x){
		if(x & 1){
			ret = mul(ret, b);
		}
		x >>= 1;
		b = mul(b, b);
	}
	
	return ret;
}

struct node {
	int nxt[30];
	int x;
	int fail;
};

struct ac {
	int tc;
	int root;
	node tree[maxn * 10];
	
	int insert(string str, int y){
		int pos = root;
		
		for(int i=0;i<str.length();i++){
			int x = str[i] - 'a';
			if(!tree[pos].nxt[x]){
				tree[pos].nxt[x] = ++tc;
			}
			pos = tree[pos].nxt[x];
		}
		
		tree[pos].x += y;
		
		return 0;
	}
	
	int build(){
		int i, j;
		
		queue <int> q;
		
		tree[root].fail = root;
		for(i=0;i<26;i++){
			if(tree[root].nxt[i]){
				tree[tree[root].nxt[i]].fail = root;
				q.push(tree[root].nxt[i]);
			}
		}
		
		while(!q.empty()){
			int pos = q.front();
			q.pop();
			
			for(i=0;i<26;i++){
				if(!tree[pos].nxt[i])continue;
				j = tree[pos].fail;
				while(j != root and !tree[j].nxt[i]){
					j = tree[j].fail;
				}
				if(tree[j].nxt[i])j = tree[j].nxt[i];
				tree[tree[pos].nxt[i]].fail = j;
				tree[tree[pos].nxt[i]].x += tree[j].x;
				q.push(tree[pos].nxt[i]);
			}
			
		}
		
		return 0;
	}
	
	int getmatrix(matrix &M){
		int i, j;
		int pos;
		
		for(pos=1;pos<=tc;pos++){
			for(i=0;i<26;i++){
				int x = tree[pos].nxt[i];
				if(x){
					M.f[pos][x] = tree[x].x;
				}else{
					j = tree[pos].fail;
					while(j != root and !tree[j].nxt[i]){
						j = tree[j].fail;
					}
					if(tree[j].nxt[i])j = tree[j].nxt[i];
					M.f[pos][j] = tree[j].x;
				}
			}
		}
		
		return 0;
	}
	
	ac(){root = tc = 1;}
} AC;

int main(){
	int i, j;
	
	E.f[1][1] = 0;
	
	cin >> n >> l;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(i=1;i<=n;i++){
		cin >> str[i];
		AC.insert(str[i], a[i]);
	}
	
	AC.build();
	AC.getmatrix(G);
	
	F = qpow(G, l);
	
	long long ans = 0;
	
	for(i=1;i<=AC.tc;i++){
		ans = max(ans, F.f[1][i]);
	}
	
	cout << ans << endl;
	
	return 0;
}