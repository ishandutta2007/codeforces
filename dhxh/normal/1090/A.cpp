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

int n, m;

priority_queue <pair <long long, long long> > q;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long ans = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		long long maxx = 0;
		m = read();
		for(j=1;j<=m;j++){
			maxx = max(maxx, 1ll * read());
		}
		q.push(make_pair(-maxx, m));
	}
	
	while(q.size() > 1){
		pair <long long, long long> a, b;
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		
		if(a.first == b.first){
			q.push(make_pair(a.first, a.second + b.second));
		}else{
			ans += (a.first - b.first) * a.second;
			q.push(make_pair(b.first, a.second + b.second));
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}