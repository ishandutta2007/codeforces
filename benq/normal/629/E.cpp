#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
// #define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

ll n,m,a,b, anc[100001][17];
ll numc[100001], sumsub[100001], sumtree[100001], depth[100001];
vi child[100001];

void maketree(int p, int node) {
	anc[node][0] = p;
	FOR(i,1,17) anc[node][i] = anc[anc[node][i-1]][i-1];
	depth[node] = depth[p]+1;
	for(int i = child[node].size()-1; i >= 0; --i) {
		if (child[node][i] == p) child[node].erase(child[node].begin()+i);
		else maketree(node,child[node][i]);
	}
}

int parent(int node, int level) {
	F0Rd(i,17) {
		if (level & (1 << i)) {
			node = anc[node][i];
		}
	}
	return node;
}
 
int LCA(int a, int b) {
	if (depth[a] < depth[b]) b = parent(b,depth[b]-depth[a]);
	if (depth[a] > depth[b]) a = parent(a,depth[a]-depth[b]);
	if (a == b) return a;
	F0Rd(i,17) {
		if (anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

double query(int x, int y) {
	int k = LCA(x,y);
	if (depth[x]>depth[y]) swap(x,y);
	double d = double(depth[x]+depth[y]-2*depth[k]);
	if (k == x) {
		int k1 = parent(y,depth[y]-depth[x]-1);
		return d+1+double(sumtree[y])/double(numc[y])+double(sumsub[x]-sumtree[k1]-numc[k1])/double(n-numc[k1]);
	} else {
		return d+1+double(sumtree[x])/double(numc[x])+double(sumtree[y])/double(numc[y]);
	}
}

void getavg(int p) {
	for(auto i: child[p]) {
		getavg(i);
		numc[p] += numc[i];
		sumtree[p] += numc[i]+sumtree[i];
	}
	numc[p] ++;
}

void genb(int p, int node) {
	sumsub[node] = sumsub[p];
	sumsub[node] -= numc[node];
	sumsub[node] += (n-numc[node]);
	for (auto i: child[node]) genb(node,i);
}

int main() {
	cin >> n >> m;
	F0R(i,n-1) {
		scanf("%d%d",&a,&b);
		child[a].pb(b), child[b].pb(a);
	}
	maketree(1,1), getavg(1);
	sumsub[1] = sumtree[1];
	for (auto i: child[1]) genb(1,i);
	cout << fixed << setprecision(10);
	F0R(i,m) {
		cin >> a >> b;
		cout << query(a,b) << endl;
	}
	return 0;
}