#include<bits/stdc++.h>
using namespace std;

vector<int> ans, ansx, ansy;

int ask(int x, int y){
	int dis;
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &dis);
	return dis;
}

void work(int l, int r){
	if(l > r) return;
	int d = l + (r - l) / 2;
	int dis = ask(d, d);
	if(dis == 0) ans.push_back(d), dis = 1;
	work(l, d - dis);
	work(d + dis, r);
}

int main(){
	work(-1e8, 1e8);
	sort(ans.begin(), ans.end());
	int t = 1;
	while(*lower_bound(ans.begin(), ans.end(), t) == t) ++t;
	for(auto v : ans){
		int dis = ask(v, t);
		if(dis == 0) ansy.push_back(v);
		dis = ask(t, v);
		if(dis == 0) ansx.push_back(v);
	}
	printf("1 %d %d\n", (int)ansy.size(), (int)ansx.size());
	for(auto v : ansy) printf("%d ", v); puts("");
	for(auto v : ansx) printf("%d ", v); puts("");
	fflush(stdout);
	return 0;
}