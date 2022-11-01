#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
const int mod = 998244353;

int n, m;

int a[maxn];
int nl[1005], nr[1005];

vector <int> vec;

long long f[1005][1005];

struct ex {
	int l, r;
};

ex p[1005];

long long dfs(int l, int r){
	int i, j;
	int x = 0, y;
	long long L = 0, R = 0;
	
	if(f[l][r] != -1)return f[l][r];
	f[l][r] = 1;
	if(l > r)return 1;
	
	for(i=1;i<=n;i++){
		if(l <= p[i].l and p[i].r <= r){
			x = i;
			break;
		}
	}
	
	if(!x)return 1;
	
	f[l][r] = dfs(p[x].l + 1, p[x].r - 1);
	
	L = dfs(l, p[x].l - 1);
	for(i=p[x].l-1;i>=l;){
		j = nl[i];
		if(j == 0x3f3f3f3f){
			i--;
			break;
		}
		L = (L + dfs(j, p[x].l - 1) * dfs(l, j - 1)) % mod;
		i = j - 1;
	}
	R = dfs(p[x].r + 1, r);
	for(i=p[x].r+1;i<=r;){
		j = nr[i];
		if(j == 0){
			i++;
			break;
		}
		R = (R + dfs(p[x].r + 1, j) * dfs(j + 1, r)) % mod;
		i = j + 1;
	}
	
	f[l][r] = f[l][r] * L % mod * R % mod;
	
	return f[l][r];
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=m;i++){
		scanf("%d", &x);
		if(!vec.size() or vec.back() != x){
			vec.push_back(x);
		}
	}
	
	m = 0;
	
	for(i=1;i<=n;i++){
		p[i].l = 0x3f3f3f3f;
		p[i].r = 0;
	}
	
	for(auto x : vec){
		a[++m] = x;
		p[a[m]].l = min(p[a[m]].l, m);
		p[a[m]].r = max(p[a[m]].r, m);
	}
	
	for(i=n;i>0;i--){
		for(j=n;j>i;j--){
			if(max(p[j].l, p[i].l) <= min(p[j].r, p[i].r) and !(p[i].l <= p[j].l and p[j].r <= p[i].r)){
				printf("0\n");
				return 0;
			}else if(max(p[j].l, p[i].l) <= min(p[j].r, p[i].r)){
				p[i].l = min(p[i].l, p[j].l);
				p[i].r = max(p[i].r, p[j].r);
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=p[i].l;j<=p[i].r;j++){
			if(a[j] < i){
				printf("0\n");
				return 0;
			}
		}
	}
	
	memset(nl, 0x3f, sizeof(nl));
	
	for(i=1;i<=n;i++){
		nl[p[i].r] = min(nl[p[i].r], p[i].l);
		nr[p[i].l] = max(nr[p[i].l], p[i].r);
	}
	
	memset(f, -1, sizeof(f));
	
	dfs(1, m);
	
	printf("%lld\n", f[1][m]);
	
	return 0;
}