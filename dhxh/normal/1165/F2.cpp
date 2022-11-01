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

int a[maxn];
int b[maxn];

struct ex {
	int d, t;
};

vector <ex> vec;

bool cmp(ex x, ex y){
	return x.d > y.d;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool check(int x){
	int i, j = 0;
	int cnt = 0, sum = 0;
	queue <ex> q;
	
	for(i=1;i<=n;i++){
		b[i] = a[i];
		sum += b[i];
	}
	
	for(ex tmp : vec){
		if(tmp.d > x)continue;
		q.push(tmp);
	}
	
	for(i=x;i>0;i--){
		while(q.size() and !b[q.front().t])q.pop();
		if(q.size() and q.front().d >= i){
			b[q.front().t]--;
			cnt++;
		}
	}
	
	return x - cnt >= 2 * (sum - cnt);
}

int main(){
	int i, j;
	int x, y;
	int l = 0, r;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		l += a[i];
	}
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		vec.push_back({x, y});
	}
	
	sort(vec.begin(), vec.end(), cmp);
	
	r = 2 * l;
	
	while(l < r){
		int mid = (l + r) / 2;
		if(!check(mid)){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	
	printf("%d\n", l);
	
	return 0;
}