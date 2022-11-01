#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, c, d;

int na = 0, nb = 0;

struct ex {
	int b;
	int p;
};

ex a[maxn];
ex b[maxn];

int prea[maxn];
int preb[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(ex x, ex y){
	return x.p < y.p;
}

int searcha(int x){
	int l = 1, r = na;
	int mid;
	
	while(l < r){
		mid = (l + r) / 2;
		if(a[mid].p <= x){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	
	return l - 1;
}

int searchb(int x){
	int l = 1, r = nb;
	int mid;
	
	while(l < r){
		mid = (l + r) / 2;
		if(b[mid].p <= x){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	
	return l - 1;
}

int main(){
	int i, j;
	char type;
	int x, y;
	int ans = 0;
	
	n = read();
	c = read();
	d = read();
	
	for(i=1;i<=n;i++){
		x = read();
		y = read();
		getchar();
		type = getchar();
		
		if(type == 'C'){
			na++;
			a[na] = (ex){x, y};
		}else{
			nb++;
			b[nb] = (ex){x, y};
		}
	}
	
	sort(a + 1, a + na + 1, cmp);
	sort(b + 1, b + nb + 1, cmp);
	
	for(i=1;i<=na;i++){
		prea[i] = max(prea[i - 1], a[i].b);
	}
	
	for(i=1;i<=nb;i++){
		preb[i] = max(preb[i - 1], b[i].b);
	}
	
	for(i=na;i>1;i--){
		int tmp = searcha(c - a[i].p);
		if(tmp){
			ans = max(ans, a[i].b + prea[min(i - 1, tmp)]);
		}
	}
	
	for(i=nb;i>1;i--){
		int tmp = searchb(d - b[i].p);
		if(tmp){
			ans = max(ans, b[i].b + preb[min(i - 1, tmp)]);
		}
	}
	
	int maxa = 0, maxb = 0;
	
	for(i=na;i>0;i--){
		if(a[i].p <= c){
			maxa = i;
			break;
		}
	}
	
	for(i=nb;i>0;i--){
		if(b[i].p <= d){
			maxb = i;
			break;
		}
	}
	
	if(maxa and maxb){
		ans = max(ans, prea[maxa] + preb[maxb]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}