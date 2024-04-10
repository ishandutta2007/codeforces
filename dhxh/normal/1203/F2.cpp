#include <bits/stdc++.h>

using namespace std;

const int maxn = 6e4 + 5;

int n, m;

vector <pair <int, int> > va, vb;

int f[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(pair <int, int> x, pair <int, int> y){
	if(x.first + x.second != y.first + y.second)return x.first + x.second > y.first + y.second;
	return x > y;
}

int main(){
	int i, j;
	int x, y;
	int ans = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		x = read();
		y = read();
		if(y >= 0){
			va.push_back(make_pair(x, y));
		}else{
			vb.push_back(make_pair(x, y));
		}
	}
	
	sort(va.begin(), va.end());
	
	for(pair <int, int> d : va){
		if(d.first <= m){
			m += d.second;
			ans++;
		}else{
			break;
		}
	}
	
	memset(f, 0xc0, sizeof(f));
	
	sort(vb.begin(), vb.end(), cmp);
	
	f[m] = ans;
	
	for(pair <int, int> d : vb){
		for(i=max(-d.second, d.first);i<=6e4;i++){
			f[i + d.second] = max(f[i] + 1, f[i + d.second]);
			ans = max(ans, f[i + d.second]);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}