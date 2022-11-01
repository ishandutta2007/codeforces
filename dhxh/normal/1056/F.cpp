#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, tc;

double c, t;

double a[105];
int p[105];

double f[105][1005];

pair <double, int> sr[105];

double s[105];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(pair <double, int> x, pair <double, int> y){
	return x > y;
}

double check(double x, double y){
	return x + y / (1.0 + x * c);
}

double getn(double x){
	double l = 0, r = t;
	double lmid, rmid;
	
	for(int i=1;i<=50;i++){
		lmid = (2.0 * l + r) / 3.0;
		rmid = (l + 2.0 * r) / 3.0;
		if(check(lmid, x) > check(rmid, x)){
			l = lmid;
		}else{
			r = rmid;
		}
	}
	
	return check(l, x);
}

int solve(){
	int i, j, k;
	double inf = 1e18;
	int ans = 0;
	
	for(i=0;i<=n;i++){
		for(j=0;j<=n*10;j++){
			f[i][j] = inf;
		}
	}
	
	f[0][0] = 0;
	
	s[0] = 1.0;
	
	for(i=1;i<=n;i++){
		s[i] = s[i - 1] / 0.9;
	}
	
	for(i=1;i<=n;i++){
		for(j=i;j>0;j--){
			for(k=n*10-p[i];k>=0;k--){
				f[j][k + p[i]] = min(f[j][k + p[i]], f[j - 1][k] + s[j] * a[i]);
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=0;j<=n*10;j++){
			if(i * 10 + getn(f[i][j]) <= t){
				ans = max(ans, j);
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

int main(){
	int i, j;
	
	tc = read();
	
	while(tc--){
		n = read();
		scanf("%lf%lf", &c, &t);
		
		for(i=1;i<=n;i++){
			sr[i].first = read();
			sr[i].second = read();
		}
		
		sort(sr + 1, sr + n + 1, cmp);
		
		for(i=1;i<=n;i++){
			a[i] = sr[i].first;
			p[i] = sr[i].second;
		}
		
		solve();
	}
	
	return 0;
}