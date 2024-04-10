#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define mo 1000000009

struct node{
	int x, y, id;
}a[N];

bool operator < (const node &a, const node &b) {
	return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}
set <node> S;
typedef set <node> :: iterator SI;
priority_queue <int> Q1;
priority_queue < int, vector<int>, greater<int> > Q2;

int cnt[N], f[N], vis[N], num[N], n;

void Push(int i){
	for(int j = a[i].x - 1;j <= a[i].x + 1;j ++){
		node tmp = (node){j, a[i].y - 1, 0};
		SI it = S.find(tmp);
		if(it != S.end()){
			if(!vis[it -> id]) f[it -> id] ++;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++){
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i;
		S.insert(a[i]);
	}
	for(int i = 1;i <= n;i ++){
		if(a[i].y){
			int pos = 0;
			for(int j = a[i].x - 1;j <= a[i].x + 1;j ++){
				node tmp = (node){j, a[i].y - 1, 0};
				SI it = S.find(tmp);
				if(it != S.end()){
					cnt[i] ++;
					pos = it -> id;
				}
			}
			if(cnt[i] == 1) f[pos] ++;
		}
	}
	for(int i = 1;i <= n;i ++) if(!f[i]) Q1.push(i), Q2.push(i);
	int pos;
	for(int i = 1;i <= n;i ++){
		if(i & 1){while(vis[Q1.top()] || f[Q1.top()]) Q1.pop();pos = Q1.top();}else{while(vis[Q2.top()] || f[Q2.top()]) Q2.pop();pos = Q2.top();		}
		vis[pos] = 1;
		num[i] = pos - 1;
		
		if(cnt[pos] == 1){
			for(int j = a[pos].x - 1;j <= a[pos].x + 1;j ++){
				node tmp = (node){j, a[pos].y - 1, 0};
				SI it = S.find(tmp);
				if(it != S.end()){
					int p = it -> id;
					if(!vis[p]) if(-- f[p] == 0) Q1.push(p), Q2.push(p);
				}
			}
		}
		for(int j = a[pos].x - 1;j <= a[pos].x + 1;j ++){
			node tmp = (node){j, a[pos].y + 1, 0};
			SI it = S.find(tmp);
			if(it != S.end()){
				int p = it -> id;
				if(vis[p]) continue;
				if(-- cnt[p] == 1) Push(p);
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++) ans = (1LL * ans * n + num[i]) % mo;
	cout << ans << endl;
	return 0;
}