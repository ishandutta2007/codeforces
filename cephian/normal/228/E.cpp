#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int MAX_K = 1e5+5;
//clear these each call
vi L;
bool vis[MAX_K*2]={0};
int cc[MAX_K*2]={0},cz=0;
vvi G,R;

void visit(int v) {
	if(vis[v]) return;
	vis[v]=1;
	for(auto u : G[v])
		visit(u);
	L.push_back(v);
}

void assign(int v, int r, vector<bool>& a) {
	if(cc[v]) return;
	cc[v] = r;
	for(auto u : R[v])
		assign(u,r,a);
	if(vis[v/2]) return;
	vis[v/2]=1;
	a[v/2]=v&1;
}
// returns an empty vector<bool> if unsatisfiable
// returns a vector<bool> v where v[r]=1 iff variable r is true in satisfying assignment
bool solve_2sat (vector<int>& a, vector<int>& b, vector<bool>& ans, int k) {
	G = vvi(2*k,vi()),R=vvi(2*k,vi());
	for(int i = 0; i < a.size(); ++i) {
		 G[a[i]^1].push_back(b[i]);
		 G[b[i]^1].push_back(a[i]);
		 R[a[i]].push_back(b[i]^1);
		 R[b[i]].push_back(a[i]^1);
	}
	for(int i = 0; i < 2*k; ++i)
		visit(i);
	fill(vis,vis+k,0);
	for(int i = L.size()-1; i >= 0; --i)
		if(!cc[L[i]])
			assign(L[i],++cz,ans);
	for(int i = 0; i < k; ++i)
		if(cc[2*i]==cc[2*i+1])
			return false;
	return true;
}

vector<int> a,b;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int c,d,e;
		cin >> c >> d >> e;
		--c; --d;
		c*=2;d*=2;
		if(e) {
			a.push_back(c+1);
			b.push_back(d);

			a.push_back(c);
			b.push_back(d+1);
		} else {
			a.push_back(c);
			b.push_back(d);

			a.push_back(c+1);
			b.push_back(d+1);
		}
	}
	vector<bool> ans(n,0);
	if(!solve_2sat(a,b,ans,n))
		cout << "Impossible\n";
	else {
		int d = 0;
		for(bool a : ans)
			d += a;
		cout << d << "\n";
		for(int i = 0; i < ans.size(); ++i)
			if(ans[i])
				cout << i+1 << " ";
		cout << "\n";
	}

	return 0;
}