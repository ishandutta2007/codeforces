#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define counti(x) (__builtin_popcount(x))
#define clz(x) (__builtin_clz(x))
#define ctz(x) (__builtin_ctz(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define Error(x) cout << #x << " = " << endl
#define X first
#define Y second
  
template <typename T, typename U> 
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}
  
template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

#define N 500105
const int nil = 0;
int n;
VI con[N];
map<int, bool> M[2][N];
int a[N], b[N];
PII c[N], d[N];
struct Complex{
	PII edge;
	int val, mi, ma;
	bool reverse;
	int son[2], father;
	void Reverse() {
		reverse ^= 1;
		swap(mi, ma);
		swap(son[0], son[1]);
	}
	bool Check();
	void PushDown();
	void PushUp();
	void clear(int i);
}tree[N];
bool Complex:: Check() {
	return tree[father].son[1] == val;
}
void Complex::clear(int i) {
  reverse = 0;
	son[0] = son[1] = father = nil;
	edge = PII(-1, -1);
	val = mi = ma = i;
}

void Complex:: PushDown() {
	if(reverse) {
		tree[son[0]].Reverse();
		tree[son[1]].Reverse();
		reverse = 0;
	}
}
int exist(int a, int b) {
  return M[1][a].count(b);
}
void Complex:: PushUp() {
  edge = PII(-1, -1);
  mi = ma = val;
	if (son[0] != nil) {
		mi = tree[son[0]].mi;
		if (edge.X == -1) {
		  if (tree[son[0]].edge.X != -1) {
		    edge = tree[son[0]].edge;
      } else {
        int a = tree[son[0]].ma;
        if (!exist(a, val)) edge = PII(a, val);
      }
    }
	}
	if (son[1] != nil) {
		ma = tree[son[1]]. ma;
		if (edge.X == -1) {
		  if (tree[son[1]].edge.X != -1) {
		    edge = tree[son[1]].edge;
      } else {
        int a = tree[son[1]].mi;
        if (!exist(a, val)) edge = PII(a, val);
      }
    }
	}
}
  
inline void Rotate(int a,bool dir);
inline void Splay(int a);
inline void PushPath(int a);
  
inline void Access(int a);
inline void ToRoot(int a);
inline void Link(int x,int y);
inline void Cut(int x, int y);
inline void Modify(int a,int c);
inline int Ask(int x, int y);
  
inline int FindRoot(int x);

int main() {

  scanf("%d", &n);
  tree[0].clear(0);
  for (int i = 0; i <= n; i++) tree[i].clear(i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    Link(u, v);
    M[0][u][v] = 1; M[0][v][u] = 1;
  }
  
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", a + i, b + i);
    M[1][a[i]][b[i]] = 1;
    M[1][b[i]][a[i]] = 1;
  }
  int rn = 0;
  for (int i = 0; i < n - 1; i++) {
    int u = a[i], v = b[i];
    if (M[0][u].count(v)) continue;
    ToRoot(u);
    Access(v);
    Splay(v);
    PII x = tree[v].edge;
    Cut(x.X, x.Y);
    M[1][x.X].erase(x.Y);
    M[1][x.Y].erase(x.X);
    c[rn] = x;
    d[rn++] = PII(u, v);
    Link(u, v);
  }
  printf("%d\n", rn);
  for (int i = 0; i < rn; i++) {
    printf("%d %d %d %d\n", c[i].X, c[i].Y, d[i].X, d[i].Y);
  } 
  return 0;
}

inline void Rotate(int a,bool dir) {
	int f = tree[a].father;
	tree[f].son[!dir] = tree[a].son[dir];
	tree[tree[f].son[!dir]].father = f;
	tree[a].son[dir] = f;
	tree[a].father = tree[f].father;
	if(tree[tree[f].father].son[0] == f || tree[tree[f].father].son[1] == f)
		tree[tree[f].father].son[tree[f].Check()] = a;
	tree[f].father = a;
	tree[f].PushUp();
}
  
inline void Splay(int a) {
  
	PushPath(a);
	while(a == tree[tree[a].father].son[0] || a == tree[tree[a].father].son[1]) {
	  
		int p = tree[tree[a].father].father;
		if(tree[p].son[0] != tree[a].father && tree[p].son[1] != tree[a].father)
			Rotate(a,!tree[a].Check());
		else if(!tree[tree[a].father].Check()) {
			if(!tree[a].Check())
				Rotate(tree[a].father,true),Rotate(a,true);
			else	Rotate(a,false),Rotate(a,true);
		}
		else {
			if(tree[a].Check())
				Rotate(tree[a].father,false),Rotate(a,false);
			else	Rotate(a,true),Rotate(a,false);
		}
	}  
	tree[a].PushUp();
}
  
inline void PushPath(int a) {
	static int stack[N];
	int top = 0;
	for(;tree[tree[a].father].son[0] == a || tree[tree[a].father].son[1] == a;a = tree[a].father)
		stack[++top] = a;
	stack[++top] = a;
	while(top)
		tree[stack[top--]].PushDown();
}
  
inline void Access(int a) {
	int last = nil;
	while(a != nil) {
		Splay(a);
		tree[a].son[1] = last;
		tree[a].PushUp();
		last = a;
		a = tree[a].father;
	}
}
inline void ToRoot(int a) {
	Access(a);
	Splay(a);
	tree[a].Reverse();
}

inline void Link(int x,int y) {
	ToRoot(x);
	tree[x].father = y;
}

inline void Cut(int x, int y) {
	ToRoot(x);
	Access(y);
	Splay(y);
	tree[y].son[0] = nil;
	tree[x].father = nil;
	tree[y].PushUp();
}
  
inline int FindRoot(int a) {
	while(tree[a].father != nil)
		a = tree[a].father;
	return a;
}