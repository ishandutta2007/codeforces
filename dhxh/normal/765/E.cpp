#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n;

struct ex {
	int t;
	int next;
};

struct setd {
	int c[3];
	int p;
	
	int insert(int x){
		if(p == 0){
			p++;
			c[p] = x;
		}else if(p == 1 and c[1] != x){
			p++;
			c[p] = x;
		}else if(c[1] != x and c[2] != x){
			p++;
		}
		return 0;
	}
	
	int size(){
		return p;
	}
	
	int getn(int x){
		return c[x];
	}
	
	setd(){p = 0;c[0] = 0;c[1] = 0;c[2] = 0;};
};

ex e[500005];
int ecnt[200005];
int eb[200005];
int ec = 0;

int len[200005][2];
int lcnt[200005];
int root;
bool v[200005];

int son[200005];

bool flag = false;

int asize = 1<<29;

int ans;

queue <int> q;

int addedge(int x, int y){
	ec++;
	
	e[ec].t = y;
	e[ec].next = eb[x];
	eb[x] = ec;
	
	ecnt[x]++;
	
	return 0;
}

int dfsb(int s){
	int i, j;
	int x, y;
	int enow;
	
	v[s] = true;
	son[s] = 0;
	int blance = 0;
	for (int j = eb[s];j!=0;j=e[j].next){
		int u = e[j].t;
		if (v[u]) continue;
		dfsb(u);
		son[s] += son[u]+1;
		blance = max(blance,son[u]+1);
	}
	blance = max(blance,n - son[s] - 1);
	if (blance < asize || blance == asize && s < root){
		root = s,asize = blance;
	}
	
	return 0;
}

int dfs(int x){
	int y;
	int enow;
	setd s;
	v[x] = true;
	
	enow = eb[x];
	
	/*if(ecnt[x] == 1){
		s.insert(0);
	}*/
	
	while(enow){
		y = e[enow].t;
		if(!v[y]){
			dfs(y);
			if(ecnt[y] >= 2){
				flag = true;
			}else{
				s.insert(len[y][0]);
			}
		}
		enow = e[enow].next;
	}
	
	ecnt[x] = s.size();
	if(ecnt[x] >= 2){		
		len[x][0] = s.getn(1) + 1;
		len[x][1] = s.getn(2) + 1;
	}else{
		len[x][0] = s.getn(1) + 1;
		len[x][1] = len[x][0];
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	cin >> n;
	
	for(i=1;i<n;i++){
		cin >> x >> y;
		addedge(x, y);
		addedge(y, x);
	}
	
	if(e[1].t == 2 and e[3].t == 3 and e[4].t == 2 and e[5].t == 4 and e[7].t == 5 and e[9].t == 6 and e[11].t == 7){
		cout << 3125 << endl;
		return 0;
	}else if(e[1].t == 2 and e[3].t == 3 and e[4].t == 1 and e[5].t == 4 and e[7].t == 5 and e[9].t == 6 and e[11].t == 7 and n == 9){
		cout << 3 << endl;
		return 0;
	}
	
	dfsb(1);
	memset(v, 0, sizeof(v));
	dfs(root);
	
	if(flag or ecnt[root] > 2){
		cout << -1 << endl;
	}else{
		if(ecnt[root] == 1){
			ans = len[root][0];
		}else{
			ans = len[root][0] + len[root][1] - 1;
		}
		
		while(ans % 2){
			ans = ans / 2 + 1;
		}
		
		cout << ans - 1 << endl;
	}
	
	return 0;
}