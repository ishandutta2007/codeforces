#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

struct ex {
	int x, y;
} a[maxn];

int w[maxn];
int cnt[maxn];
bool vis[maxn];
bool v[maxn];

vector <int> e[maxn];
vector <int> ans;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		w[i] = read();
	}
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		a[i] = {x, y};
		e[x].push_back(i);
		e[y].push_back(i);
		cnt[x]++;
		cnt[y]++;
	}
	
	queue <int> q;
	
	for(i=1;i<=n;i++){
		if(cnt[i] <= w[i]){
			q.push(i);
			vis[i] = true;
		}
	}
	
	while(q.size()){
		int x = q.front();
		q.pop();
		for(auto i : e[x]){
			int y = a[i].y;
			if(y == x) y = a[i].x;
			if(!v[i]){
				v[i] = true;
				ans.push_back(i);
			}
			if(vis[y]) continue;
			cnt[y]--;
			if(cnt[y] <= w[y]){
				vis[y] = true;
				q.push(y);
			}
		}
	}
	
	reverse(ans.begin(), ans.end());
	if(ans.size() == m){
		printf("ALIVE\n");
		for(auto x : ans){
			printf("%d ", x);
		}
		printf("\n");
	}else{
		printf("DEAD\n");
	}
	
	return 0;
}