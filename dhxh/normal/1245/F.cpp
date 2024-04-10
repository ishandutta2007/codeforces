#include <bits/stdc++.h>

using namespace std;

long long f[40][3][3];

long long l, r;
long long ta, tb;

int getn(long long x, int y){
	return (x >> y) & 1;
}

long long dfs(int x, int a, int b){
	if(x == -1)return 1;
	long long &ret = f[x][a][b];
	if(ret != -1)return ret;
	ret = 0;
	
	int la, lb, ra, rb;
	
	if(a == 0){
		la = 0, ra = getn(ta, x);
	}else{
		la = 0, ra = 1;
	}
	
	if(b == 0){
		lb = 0, rb = getn(tb, x);
	}else{
		lb = 0, rb = 1;
	}
	
	for(int i=la;i<=ra;i++){
		for(int j=lb;j<=rb;j++){
			if((i + j) == (i ^ j)){
				ret += dfs(x - 1, a | (i < getn(ta, x)), b | (j < getn(tb, x)));
			}
		}
	}
	
	return ret;
}

long long getans(long long a, long long b){
	if(a < 0 or b < 0)return 0;
	memset(f, -1, sizeof(f));
	ta = a, tb = b;
	return dfs(33, 0, 0);
}

int main(){
	int i, j;
	int t;
	
	cin >> t;
	
	while(t--){
		cin >> l >> r;
		long long ans = getans(r, r) - 2ll * getans(l - 1, r) + getans(l - 1, l - 1);
		
		cout << ans << endl;
	}
	
	return 0;
}