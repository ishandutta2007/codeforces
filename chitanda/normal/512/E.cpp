#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

vector<pii> step;
int n;
set<int> g[1010];

bool check(bool k){
	auto it_r = g[0].begin();
	auto it_l = it_r++;
	while(it_r != g[0].end()){
		if(*it_r != *it_l + 1){
			if(k == 0) step.pb(mkp(*it_l, *it_r));
			g[*it_l].erase(*it_r);
			g[*it_r].erase(*it_l);
			for(int i = *it_l + 1; i <= *it_r - 1; ++i)
				if(g[i].find(*it_l) != g[i].end() && g[i].find(*it_r) != g[i].end()){
					if(k == 1) step.pb(mkp(0, i));
					g[0].insert(i);
					g[i].insert(0);
				}
			return 1;
		}
		++it_l, ++it_r;
	}
	return 0;
}

void work(bool k){
	while(check(k));
}

int main(){
	scanf("%d", &n);
	int u, v;
	for(int i = 0; i < n - 3; ++i){
		scanf("%d%d", &u, &v);
		--u, --v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i = 0; i < n; ++i)
		g[i].insert((i + 1) % n), g[i].insert((i + n - 1) % n);
	work(0);
	int m = step.size();
	auto pre = step;

	for(int i = 0; i < n; ++i) g[i].clear();
	for(int i = 0; i < n - 3; ++i){
		scanf("%d%d", &u, &v);
		--u, --v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i = 0; i < n; ++i)
		g[i].insert((i + 1) % n), g[i].insert((i + n - 1) % n);
	step.clear();
	work(1);
	m += step.size();
	reverse(step.begin(), step.end());
	printf("%d\n", m);
	for(pii v : pre)
		printf("%d %d\n", v.fi + 1, v.se + 1);
	for(pii v : step)
		printf("%d %d\n", v.fi + 1, v.se + 1);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}