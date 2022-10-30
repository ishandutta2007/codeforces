#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
struct seg {
	int num_c = 0;
	int cc[10][2];
	int val[10][2];
};

int n,m,q;

int uf[40];
int used[40];

int id(int v) {
	return (uf[v]==v)?v:uf[v]=id(uf[v]);
}

bool merge(int v, int u) {
	if(id(v) == id(u)) return false;
	uf[id(v)] = id(u);
	return true;
}

seg merge_st(const seg& a, const seg& b,seg& s) {
	int n2=n*2,n4=n*4;
	int sz = 0;
	for(int i = 0; i < n4; ++i) {
		uf[i] = i;
		used[i] = 0;
	}
	int merges = 0;
	for(int i = 0; i < n; ++i) {
		s.val[i][0] = a.val[i][0];
		s.val[i][1] = b.val[i][1];
		if(a.val[i][1] == b.val[i][0])
			merges += merge(a.cc[i][1],b.cc[i][0]+n2);
	}
	for(int i = 0; i < n; ++i) {
		used[id(a.cc[i][0])] = 1;
		used[id(b.cc[i][1]+n*2)] = 1;
	}
	for(int i = 1; i < n4; ++i)
		used[i] += used[i-1];
	s.num_c = a.num_c + b.num_c - merges;
	for(int i = 0; i < n; ++i) {
		s.cc[i][0] = used[id(a.cc[i][0])]-1;
		s.cc[i][1] = used[id(b.cc[i][1]+n2)]-1;
	}
	return s;
}

const int M = 1e5+5;
int g[10][M],l[4*M],r[4*M];
seg st[4*M];

void build(int v, int i, int j) {
	l[v] = i, r[v] = j;
	if(i == j) {
		for(int k = 0; k < n; ++k)
			st[v].val[k][0] = st[v].val[k][1] = g[k][i];
		st[v].cc[0][0] = st[v].cc[0][1] = 0;
		for(int k = 1; k < n; ++k)
			for(int b = 0; b < 2; ++b)
				st[v].cc[k][b] = st[v].cc[k-1][b] + (st[v].val[k][b] != st[v].val[k-1][b]);
		st[v].num_c = st[v].cc[n-1][0]+1;
	} else {
		build(v*2,i,(i+j)/2);
		build(v*2+1,(i+j)/2+1,j);
		merge_st(st[v*2],st[v*2+1],st[v]);
	}
}

void query(int v, int i, int j,seg& s) {
	if(i <= l[v] && r[v] <= j) {
		s = st[v];
	} else {
		int m = (l[v]+r[v])/2;
		if(j <= m) query(v*2,i,j,s);
		else if(m < i) query(v*2+1,i,j,s);
		else {
			seg a,b;
			query(v*2,i,j,a);
			query(v*2+1,i,j,b);
			merge_st(a,b,s);
		}
	}
}

seg s;

int main() {
	scanf("%d %d %d",&n,&m,&q);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d",&g[i][j]);
	build(1,0,m-1);
	while(q--) {
		int l,r;
		scanf("%d %d",&l,&r); --l; --r;
		query(1,l,r,s);
		printf("%d\n",s.num_c);
	}
	return 0;
}