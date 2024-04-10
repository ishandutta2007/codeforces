#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 3005;

int n, m;

struct ex {
	int p;
	long long c;
};

ex p[maxn];

vector <ex> par[maxn];

int b[maxn];

long long ans = 3000ll * 1e9;

vector <ex> tmp;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(ex x, ex y){
	return x.c < y.c;
}

long long check(int x){
	int i, j;
	int cnt = par[1].size();
	long long ret = 0;
	
	memset(b, 0, sizeof(b));
	
	for(i=2;i<=m;i++){
		if(par[i].size() >= x){
			b[i] = par[i].size() - x + 1;
			for(j=0;j<b[i];j++){
				ret += par[i][j].c;
				cnt++;
			}
		}
	}
	
	if(cnt >= x){
		return ret;
	}
	
	tmp.clear();
	
	for(i=2;i<=m;i++){
		for(j=b[i];j<par[i].size();j++){
			tmp.push_back(par[i][j]);
		}
	}
	
	sort(tmp.begin(), tmp.end(), cmp);
	
	for(i=0;i<x-cnt;i++){
		ret += tmp[i].c;
	}
	
	return ret;
}

int main(){
	int i, j;
	int l, r;
	int midl, midr;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		p[i].p = read();
		p[i].c = read();
		par[p[i].p].push_back(p[i]);
	}
	
	for(i=1;i<=m;i++){
		sort(par[i].begin(), par[i].end(), cmp);
	}
	
	l = 1;
	r = n;
	
	while(l + 2 < r){
		midl = (r + 2 * l) / 3;
		midr = (2 * r + l) / 3;
		
		if(check(midl) < check(midr)){
			r = midr;
		}else{
			l = midl;
		}
	}
	
	for(i=l;i<=r;i++){
		ans = min(check(i), ans);
	}
	
	printf("%I64d\n", ans);
	
	return 0;
}