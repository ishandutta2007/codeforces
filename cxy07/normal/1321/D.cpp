//Code By CXY
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,m,k,s,t,ans1,ans2;
int dis[MAXN],cnt[MAXN],p[MAXN];
vector<int> G[MAXN],rev[MAXN];
queue<int> Q;
bool vis[MAXN];

signed main () {
	cin >> n >> m;
	for(register int i = 1,x,y;i <= m; ++i) {
		cin >> x >> y;
		G[x].push_back(y);
		rev[y].push_back(x);
	}
	cin >> k;
	for(register int i = 1;i <= k; ++i)
		cin >> p[i];
	s = p[1],t = p[k];
	memset(dis,0x3f,sizeof dis);
	dis[t] = 0,cnt[t] = 1;
	Q.push(t);
	while(!Q.empty()) {
		int top = Q.front();
		Q.pop(); vis[top] = false;
		for(register int i = 0;i < rev[top].size(); ++i) {
			int x = rev[top][i];
			if(dis[x] > dis[top] + 1) {
				dis[x] = dis[top] + 1;
				cnt[x] = cnt[top];
				if(!vis[x]) {
					vis[x] = true;
					Q.push(x);
				}
			} else if(dis[x] == dis[top] + 1) cnt[x] += cnt[top];
		}
	}
	for(register int i = 1,x,to;i < k; ++i) {
		x = p[i],to = p[i + 1];
		if(dis[x] != dis[to] + 1) ans2++,ans1++;
		else ans2 += (bool)(cnt[x] - cnt[to]);
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}