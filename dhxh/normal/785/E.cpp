#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;

struct block {
	int n;
	int a;
};

block bc[500][500];

int binfo[500];

int bsize = 0, bnum = 0;

int a[maxn];

int ainfo[maxn];
int ab[maxn];

bool cmp(block x, block y){
	return x.n < y.n;
}

int read(){
	int x = 0;
	char ch = getchar();
	
	while('0' > ch or ch > '9'){
		ch = getchar();
	}
	
	while('0' <= ch and ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x;
}

int update(int p, int x){
	int i, j, k;
	int s = 0;
	block tmp;
	
	i = ab[p];
	
	k = ainfo[p];
	
	bc[i][k].n = x;
	
	if(x > a[p]){
		while(k + 1 <= binfo[i] and bc[i][k].n > bc[i][k + 1].n){
			ainfo[p] = k + 1;
			ainfo[bc[i][k + 1].a] = k;
			tmp = bc[i][k];
			bc[i][k] = bc[i][k + 1];
			bc[i][k + 1] = tmp;
			k++;
		}
	}else{
		while(k - 1 > 0 and bc[i][k].n < bc[i][k - 1].n){
			ainfo[p] = k - 1;
			ainfo[bc[i][k - 1].a] = k;
			tmp = bc[i][k];
			bc[i][k] = bc[i][k - 1];
			bc[i][k - 1] = tmp;
			k--;
		}
	}
	
	return 0;
}

int query_block_rank(int pos, int k){
	int l = 0, r = binfo[pos];
	int mid;
	
	while(l < r - 1){
		mid = (l + r) / 2;
		if(bc[pos][mid].n >= k){
			r = mid;
		}else{
			l = mid;
		}
	}
	
	if(bc[pos][r].n < k){
		return r;
	}else{
		return l;
	}
}

int query_rank(int l, int r, int k){
	int i, j;
	int s = 0;
	int ret = 0;
	
	i = 0;
	
	while(s < l - 1){
		i++;
		s += binfo[i];
	}
	
	for(j=min(s, r);j>=l;j--){
		if(a[j] < k){
			ret++;
		}
	}
	
	i++;
	
	while(s + binfo[i] <= r){
		ret += query_block_rank(i, k);
		s += binfo[i];
		i++;
	}
	
	for(j=s+1;j<=r;j++){
		if(a[j] < k){
			ret++;
		}
	}
	
	return ret;
}

int main(){
	int i, j;
	long long tmp;
	int x, y;
	int l, r, k;
	long long ans = 0;
	
	n = read();
	m = read();
	
	while(bsize * bsize < n){
		bsize++;
	}
	
	while(bnum * bsize < n){
		bnum++;
		if(bnum * bsize > n){
			binfo[bnum] = n - (bnum - 1) * bsize;
		}else{
			binfo[bnum] = bsize;
		}
	}
	
	binfo[bnum + 1] = 1;
	
	for(i=1;i<=n;i++){
		a[i] = i;
		x = (i - 1) / bsize + 1;
		y = (i - 1) % bsize + 1;
		bc[x][y].n = a[i];
		bc[x][y].a = i;
		ainfo[i] = y;
		ab[i] = x;
	}
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		tmp = min(x, y);
		y = max(x, y);
		x = tmp;
		if(x != y){
			if(x + 1 != y){
				tmp = query_rank(x + 1, y - 1, a[x]);
				ans -= tmp;
				ans += (y - x - 1) - tmp;
				tmp = query_rank(x + 1, y - 1, a[y]);
				ans += tmp;
				ans -= (y - x - 1) - tmp;
			}
			
			if(a[x] < a[y]){
				ans++;
			}else{
				ans--;
			}
			
			tmp = a[x];
			update(x, a[y]);
			a[x] = a[y];
			update(y, tmp);
			a[y] = tmp;
		}
		printf("%I64d\n", ans);
	}
	
	return 0;
}