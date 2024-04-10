#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t, d;

pair <int, int> a[maxn];
int anss[maxn];
int ans = 0;
queue <int> q;
int last[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	m = read();
	d = read();
	
	for(i=1;i<=n;i++){
		a[i] = make_pair(read(), i);
	}
	
	sort(a + 1, a + n + 1);
	
	ans = 1;
	last[1] = a[1].first;
	anss[a[1].second] = 1;
	q.push(1);
	
	for(i=2;i<=n;i++){
		if(last[q.front()] + d < a[i].first){
			anss[a[i].second] = q.front();
			last[q.front()] = a[i].first;
			q.push(q.front());
			q.pop();
		}else{
			ans++;
			anss[a[i].second] = ans;
			last[ans] = a[i].first;
			q.push(ans);
		}
	}
	
	printf("%d\n", ans);
	
	for(i=1;i<=n;i++){
		printf("%d ", anss[i]);
	}
	printf("\n");
	
	return 0;
}