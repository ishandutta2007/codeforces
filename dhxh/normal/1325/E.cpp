#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
const int M = 1e6;

int a[maxn];
int c[maxn];
vector <int> vec[maxn];
vector <int> prime;
vector <int> e[maxm];
bool vis[maxm];
bool inq[maxm];
int dis[maxm];
int dep[maxm];

int ans = 0x3f3f3f3f;
int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int init(){
	int i, j;
	for(i=2;i<=1000;i++){
		bool flag = false;
		for(j=2;j*j<=i;j++){
			if(i % j == 0){
				flag = true;
			}
		}
		if(!flag) prime.push_back(i);
	}
	
	return 0;
}

bool cmp(int x, int y){
	if(vec[x].size() != vec[y].size()){
		return vec[x].size() < vec[y].size();
	}
	for(int i=0;i<vec[x].size();i++){
		if(vec[x][i] != vec[y][i]){
			return vec[x][i] < vec[y][i];
		}
	}
	return false;
}

bool equal(int x, int y){
	if(vec[x].size() != vec[y].size()){
		return false;
	}
	for(int i=0;i<vec[x].size();i++){
		if(vec[x][i] != vec[y][i]){
			return false;
		}
	}
	return true;
}

int solve(int x){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(inq, 0, sizeof(inq));
	queue <int> q;
	dis[x] = 0;
	q.push(x);
	while(q.size()){
		x = q.front();
		q.pop();
		vis[x] = true;
		for(auto y : e[x]){
			if(vis[y]) continue;
			ans = min(ans, dis[x] + dis[y] + 1);
			if(!inq[y]) q.push(y), inq[y] = true;
			dis[y] = min(dis[y], dis[x] + 1);
		}
	}
	return 0;
}

int main(){
	int i, j;
	int x, y;
	srand(time(0));
	init();
	
	n = read();
	
	for(i=1;i<=n;i++){
		x = a[i] = read();
		for(auto j : prime){
			if(j * j > a[i]) break;
			int cnt = 0;
			while(x % j == 0) cnt++, x /= j;
			if(cnt & 1) vec[i].push_back(j);
		}
		if(x > 1) vec[i].push_back(x);
		sort(vec[i].begin(), vec[i].end());
		if(!vec[i].size()){
			printf("1\n");
			return 0;
		}
		c[i] = i;
	}
	
	sort(c + 1, c + n + 1, cmp);
	
	for(i=1;i<n;i++){
		if(equal(c[i], c[i + 1])){
			printf("2\n");
			return 0;
		}
	}
	
	queue <int> q;
	memset(dis, 0x3f, sizeof(dis));
	
	for(i=1;i<=n;i++){
		if(vec[i].size() == 1){
			q.push(vec[i][0]);
			inq[vec[i][0]] = true;
			dis[vec[i][0]] = 1;
		}else{
			e[vec[i][0]].push_back(vec[i][1]);
			e[vec[i][1]].push_back(vec[i][0]);
		}
	}
	
	while(q.size()){
		x = q.front();
		q.pop();
		vis[x] = true;
		for(auto y : e[x]){
			if(vis[y]) continue;
			ans = min(ans, dis[x] + dis[y] + 1);
			if(!inq[y]) q.push(y), inq[y] = true;
			dis[y] = min(dis[y], dis[x] + 1);
		}
	}
	
	for(auto i : prime){
		if(e[i].size()) solve(i);
	}
	
	if(ans == 0x3f3f3f3f) ans = -1;
	
	printf("%d\n", ans);
	
	return 0;
}