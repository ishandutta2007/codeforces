//Code By CXY
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 1010;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,ans = 1,cnt,siz,dep[MAXN];
int g1,g2;
bool del[MAXN];
vector<int> G[MAXN];

void Getfar(int x,int fa,int &sav) {
	dep[x] = dep[fa] + 1;
	if(sav == 0 || dep[x] > dep[sav]) sav = x;
	for(register int i = 0,to;i < G[x].size(); ++i) {
		to = G[x][i];
		if(to == fa || del[to]) continue;
		Getfar(to,x,sav);	
	}
}

bool Getway(int x,int fa) {
	if(x == g1 || x == g2) return true;
	for(register int i = 0,to;i < G[x].size(); ++i) {
		to = G[x][i];
		if(to == fa || del[to]) continue;
		if(Getway(to,x)) return true; 
	}
	return false;
}

void Del(int x,int fa) {
	del[x] = true;
	for(register int i = 0,to;i < G[x].size(); ++i) {
		to = G[x][i];
		if(to == fa || del[to]) continue;
		Del(to,x);
	}
}

signed main () {
	cin >> n; 
	for(register int i = 1,x,y;i < n; ++i) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	siz = n;
	while(1) {
		int tmp = 1,x = 0,y = 0,lca;
		while(del[tmp]) tmp++;
		assert(tmp <= n);
		memset(dep,0,sizeof dep);
		Getfar(tmp,0,x);
		memset(dep,0,sizeof dep);
		Getfar(x,0,y);
		if(x == y) {cout << "! " << x << endl; return 0;}
		cout << "? " << x << ' ' << y << endl;
		g1 = x,g2 = y;
		//cnt++;
		//if(cnt > n / 2) return 0;
		cin >> lca;
		cout.flush();
		for(register int i = 0,to;i < G[lca].size(); ++i) {
			to = G[lca][i];
			if(Getway(to,lca)) Del(to,lca);
		}
	}
	return 0;
}