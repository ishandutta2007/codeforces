#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

long long n, m;

long long ans[maxn];

struct ex {
	long long x;
	long long isl;
};

ex p[2 * maxn];

bool cmp(ex x, ex y){
	return x.x < y.x;
}

int main(){
	long long i, j;
	long long l, r;
	long long x;
	long long cnt = 0;
	
	cin >> n;
	
	for(i=1;i<=2 * n;i++){
		cin >> x;
		p[i].x = x;
		m = max(m, x);
		if(i & 1){
			p[i].isl = 1;
		}else{
			p[i].x += 1;
			p[i].isl = -1;
		}
	}
	
	sort(p + 1, p + 2 * n + 1, cmp);
	
	x = 0;
	
	for(i=1;i<=2 * n;i++){
		ans[cnt] += (p[i].x - x);
		cnt += p[i].isl;
		x = p[i].x;
	}
	
	cout << ans[1];
	
	for(i=2;i<=n;i++){
		cout << " " << ans[i];
	}
	
	cout << endl;
	
	return 0;
}