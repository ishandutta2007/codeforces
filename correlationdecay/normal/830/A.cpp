#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <iostream>
#define maxn 2009
using namespace std;
int n, m, p;
int a[maxn], b[maxn];

struct node{
	int l, r;
	bool operator < (const node &rhs)const{
		if(r == rhs.r)
			return l < rhs.l;
		else
			return r < rhs.r;
	}
}X[maxn];

bool check(long long t){
	int tot = 0;
	for(int i = 1; i <= m; i++){
		if(abs(b[i] - p) > t)
			continue;
		long long res = t - abs(b[i] - p);
		int L = n + 1,  R = 0;
		for(int j = 1; j <= n; j++){
			if(b[i] - res <= a[j] && a[j] <= b[i] + res){
				L = min(L, j);
				R = max(R, j);
			}
		}
		if(L <= R){
			//cout << L << " " << R << endl;
			X[tot].l = L;
			X[tot].r = R;
			tot++;
		}
	}
	if(tot < n) return 0;
	sort(X, X + tot);
	int p = 1, q = 0;
	while(p <= n && q < tot){
		if(X[q].l <= p && p <= X[q].r){
			p++; q++;
		}
		else{
			q++;
		}
	}
	return p > n;
}

int main(){
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++)	cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	long long L = 0, R = 3e9;
	//check(50);
	
	while(L < R){
		long long M = (L + R) >> 1;
		if(check(M))
			R = M;
		else
			L = M + 1;
	} 
	
	cout << R << endl;
	return 0;
}