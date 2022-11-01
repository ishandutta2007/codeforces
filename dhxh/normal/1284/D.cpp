#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int sa[maxn], ea[maxn], sb[maxn], eb[maxn];
int c[maxn];
bool vis[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(int x, int y){
	if(sa[x] != sa[y]) return sa[x] < sa[y];
	return ea[x] < ea[y];
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d", &sa[i], &ea[i], &sb[i], &eb[i]);
		c[i] = i;
	}
	
	sort(c + 1, c + n + 1, cmp);
	
	priority_queue <pair <int, int> > q, qa, qb;
	
	q.push(make_pair(-ea[c[1]], c[1]));
	qa.push(make_pair(sb[c[1]], c[1]));
	qb.push(make_pair(-eb[c[1]], c[1]));
	
	for(i=2;i<=n;i++){
		int x = c[i];
		while(q.size() and ea[q.top().second] < sa[x]){
			vis[q.top().second] = true;
			q.pop();
		}
		while(qa.size() and vis[qa.top().second]){
			qa.pop();
		}
		while(qb.size() and vis[qb.top().second]){
			qb.pop();
		}
		
		if((qa.size() and eb[x] < sb[qa.top().second]) or (qb.size() and sb[x] > eb[qb.top().second])){
			printf("NO\n");
			return 0;
		}
		q.push(make_pair(-ea[c[i]], c[i]));
		qa.push(make_pair(sb[c[i]], c[i]));
		qb.push(make_pair(-eb[c[i]], c[i]));
	}
	
	for(i=1;i<=n;i++){
		swap(sa[i], sb[i]);
		swap(ea[i], eb[i]);
		c[i] = i;
	}
	
	sort(c + 1, c + n + 1, cmp);
	
	while(q.size())q.pop();
	while(qa.size())qa.pop();
	while(qb.size())qb.pop();
	
	q.push(make_pair(-ea[c[1]], c[1]));
	qa.push(make_pair(sb[c[1]], c[1]));
	qb.push(make_pair(-eb[c[1]], c[1]));
	memset(vis, 0, sizeof(vis));
	
	for(i=2;i<=n;i++){
		int x = c[i];
		while(q.size() and ea[q.top().second] < sa[x]){
			vis[q.top().second] = true;
			q.pop();
		}
		while(qa.size() and vis[qa.top().second]){
			qa.pop();
		}
		while(qb.size() and vis[qb.top().second]){
			qb.pop();
		}
		
		if((qa.size() and eb[x] < sb[qa.top().second]) or (qb.size() and sb[x] > eb[qb.top().second])){
			printf("NO\n");
			return 0;
		}
		q.push(make_pair(-ea[c[i]], c[i]));
		qa.push(make_pair(sb[c[i]], c[i]));
		qb.push(make_pair(-eb[c[i]], c[i]));
	}
	
	printf("YES\n");
	
	return 0;
}