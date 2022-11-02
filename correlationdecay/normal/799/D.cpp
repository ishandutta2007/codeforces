#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define maxn 500009
using namespace std;
const long long INF = 1e6;
long long a, b, h, w;
int n;
long long aa[maxn];
long long res;
map<int,int>mp;
long long num[maxn], cnt[maxn];
int tot;
bool cmp(long long a, long long b){
	return a > b;
}
void dfs(int cur, long long x, long long a, long long b, long long ans){
	if(x >= a){
		//cout << x << endl;
		int sum = 0;
		long long y = 1;
		for(int i = 0; i < tot; i++){
			for(int j = 0; j < cnt[i]; j++){
				y *= num[i];
				sum++;
				if(y >= b){
					res = min(res, ans + sum);
					return;
				}
			}
		}
		return;
	}
	if(cur == tot){
		return;
	}
	long long val = 1;
	for(int i = 0; i <= cnt[cur]; i++){
		cnt[cur] -= i;
		dfs(cur + 1, x * val, a, b, ans + i);
		cnt[cur] += i;
		if(x * val >= a)
			return;
		val *= num[cur];
	}
	return;
}

long long solve(int a, int b, int h, int w, int n){
	long long ans  = INF;
	if(a <= h && b <= w)
		return 0;
	else if(a <= h){
		long long cur = 1;
		for(int i = 1; i <= n; i++){
			cur *= aa[i];
			if(cur * w >= b)
				return i;
		}
		return INF;
	}
	else if(b <= w){
		long long cur = 1;
		for(int i = 1; i <= n; i++){
			cur *= aa[i];
			if(cur * h >= a)
				return i;
		}
		return INF;
	}
	long long x = (a + h - 1) / h;
	long long y = (b + w - 1) / w;
	//cout << x << " " << y << endl;
	mp.clear(); tot = 0;
	int curx = 1, cury = 1;
	for(int i = 1; i <= n; i++){
		mp[-aa[i]]++;
		if(curx < x)
			curx *= aa[i];
		else if(cury < y)
			cury *= aa[i];
		else
			break;
	}
	for(auto it = mp.begin(); it != mp.end(); ++it){
		num[tot] = -(it -> first);
		cnt[tot] = it -> second;
		tot++;
	}
	//cout << num[0] << " " << cnt[0] << endl;
	res = INF;
	dfs(0, 1, x, y, 0);
	return res;
}
int main(){
	cin >> a >> b >> h >> w >> n;
	for(int i = 1; i <= n ; i++)
		scanf("%lld", &aa[i]);
	sort(aa + 1, aa + 1 + n, cmp);
	long long ans = INF;
	ans = min(ans, solve(a, b, h, w, n));
	ans = min(ans, solve(b, a, h, w, n));
	if(ans >= INF) ans = -1;
	cout << ans << endl;
	return 0;
}