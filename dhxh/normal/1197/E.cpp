#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
long long mod = 1e9 + 7;
long long inf = 0x3f3f3f3f3f3f3f3f;

long long n, m = 0;

struct ex {
	long long x, y;
	
	ex(){
		x = inf, y = 0;
	}
};

ex a[maxn];
int c[maxn];
int p[maxn];
map <int, int> s;

ex merge(ex x, ex y){
	if(x.x < y.x){
		return x;
	}else if(x.x > y.x){
		return y;
	}else{
		ex ret;
		ret.x = x.x, ret.y = x.y + y.y;
		if(ret.y > mod)ret.y -= mod;
		return ret;
	}
}

struct bt {
	ex tree[maxn];
	
	int lowbit(int x){
		return x & -x;
	}
	
	ex sum(int p){
		ex ret;
		while(p){
			ret = merge(ret, tree[p]);
			p -= lowbit(p);
		}
		return ret;
	}
	
	int update(int p, ex x){
		while(p <= n + 1){
			tree[p] = merge(tree[p], x);
			p += lowbit(p);
		}
		return 0;
	}
} tree;

bool cmpa(ex x, ex y){
	return x.x < y.x;
}

bool cmpb(int x, int y){
	return a[x].y < a[y].y;
}

int main(){
	int i, j;
	ex ans;
	long long x, y;
	long long maxx = 0;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%lld%lld", &a[i].x, &a[i].y);
		swap(a[i].x, a[i].y);
		maxx = max(maxx, a[i].x);
		c[i] = i;
	}
	
	sort(a + 1, a + n + 1, cmpa);
	sort(c + 1, c + n + 1, cmpb);
	
	for(i=1;i<=n;i++){
		p[c[i]] = i;
		if(!s.count(a[c[i]].y))s[a[c[i]].y] = i;
	}
	
	ex tmp;
	tmp.x = 0, tmp.y = 1;
	
	tree.update(1, tmp);
	
	for(i=1;i<=n;i++){
		x = s.upper_bound(a[i].x) -> second;
		ex ret = tree.sum(x);
		ret.x += a[i].x;
		if(a[i].y > maxx){
			ans = merge(ans, ret);
		}
		ret.x -= a[i].y;
		tree.update(p[i] + 1, ret);
	}
	
	printf("%lld\n", ans.y);
	
	return 0;
}