#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

int a[maxn];

int cnt[maxn][2];

bool st[maxn];

int ans;

int main(){
	int i, j;
	int x = 0;
	bool sta = 1;
	int l, r;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	
	if(a[n] != m){
		n++;
		a[n] = m;
	}
	
	for(i=1;i<=n;i++){
		cnt[i][sta] = cnt[i - 1][sta] + a[i] - x;
		cnt[i][!sta] = cnt[i - 1][!sta];
		st[i] = sta;
		sta = !sta;
		x = a[i];
	}
	
	x = 0;
	
	ans = cnt[n][1];
	
	for(i=1;i<=n;i++){
		if(a[i] - x > 1){
			if(st[i] == 1){
				l = cnt[i][1] - cnt[i - 1][1];
				ans = max(ans, cnt[i - 1][1] + cnt[n][0] - cnt[i][0] + l - 1);
			}else{
				l = cnt[i][0] - cnt[i - 1][0];
				ans = max(ans, cnt[i - 1][1] + cnt[n][0] - cnt[i][0] + l - 1);
			}
		}
		x = a[i];
	}
	
	cout << ans << endl;
	
	return 0;
}