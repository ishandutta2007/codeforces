#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
Int a[1 << 21];
Int n, m, q;
Int cnt[25][2], rev[25];


vector<Int> solve(Int x, Int l, Int r){
	vector<Int> res;
	if(x == 0){
		res.push_back(a[l]);
		return res;
	}
	Int mid = (l + r) / 2;
	vector<Int> lv, rv;
	lv = solve(x - 1, l, mid);
	rv = solve(x - 1, mid, r);
	Int lp = 0, rp = 0;
	while(lp < lv.size() || rp < rv.size()){
		if(lp == lv.size()){
			res.push_back(rv[rp++]);
		}
		else if(rp == rv.size()){
			res.push_back(lv[lp]);
			cnt[x][0] += rp;
			lp++;
		}
		else if(lv[lp] <= rv[rp]){
			res.push_back(lv[lp]);
			cnt[x][0] += rp;
			lp++;
		}
		else{
			res.push_back(rv[rp++]);
		}
	}
	swap(lv, rv);
	lp = 0, rp = 0;
	while(lp < lv.size() || rp < rv.size()){
		if(lp == lv.size()){
			rp++;
		}
		else if(rp == rv.size()){
			cnt[x][1] += rp;
			lp++;
		}
		else if(lv[lp] <= rv[rp]){
			cnt[x][1] += rp;
			lp++;
		}
		else{
			rp++;
		}
	}
	return res;
}

int main(){
	scanf("%d", &n);
	for(Int i = 0;i < (1 << n);i++)scanf("%d", &a[i]);
	
	solve(n, 0, 1 << n);
	scanf("%d", &m);
	while(m--){
		scanf("%d", &q);
		for(Int i = q;i >= 0;i--)rev[i] ^= 1;
		Int res = 0;
		for(Int i = 0;i <= n;i++){res += cnt[i][rev[i]];}
		printf("%lld\n", res);
	}
    return 0;
}