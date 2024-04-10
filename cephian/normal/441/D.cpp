#include <algorithm>
#include <iostream>
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

const int N = 3005;
int p[N],q[N],n,m;
vi a,b;

int test(int steps) {
	for(int i = 1; i <= n; ++i)
		q[i] = p[i];
	int ans = 0;
	a.clear();
	b.clear();
	if(steps == 0) return 0;
	for(int i = 1; i <= n; ++i) {
		while(q[i] != i) {
			int sw = q[i];
			for(int r = q[i]; r != i; r = q[r])
				sw = min(sw,r);
			a.push_back(i);
			b.push_back(sw);
			swap(q[i],q[sw]);
			++ans;
			if(ans == steps)
				return ans;
		}
	}
	return ans;
}

int uf[N];

int id(int v) {
	return (uf[v]==v)?v:uf[v] = id(uf[v]);
}

void merge(int u, int v) {
	uf[id(u)] = id(v);
}

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> p[i];
	cin >> m;
	int dist = test(0x7fffffff);
	if(dist >= m) {
		test(dist-m);
		cout << a.size() << "\n";
		for(int i = 0; i < a.size(); ++i)
			cout << a[i] << " " << b[i] << " ";
		cout << "\n";
	} else {
		for(int i = 1; i <= n; ++i)
			uf[i] = i;
		for(int i = 1; i <= n; ++i)
			merge(i,p[i]);
		cout << m-dist << "\n";
		for(int j = 2; j <= n; ++j) {
			if(id(1) == id(j)) continue;
			swap(p[1],p[j]);
			merge(1,j);
			cout << "1 " << j << " ";
			++dist;
			if(dist == m) {
				cout << "\n";
				return 0;
			}
		}
	}
	return 0;
}