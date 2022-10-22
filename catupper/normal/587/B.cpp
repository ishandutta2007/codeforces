#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL
Int n, k, l;          
Int res;
Int bit[2][1080000];
Int a[1080000];
vector<Int> nums;
Int sum(Int *bit, Int pos){
	pos++;
	Int res = 0;
	while(pos){
		 res += bit[pos];
		 res %= MOD;
		 pos -= pos & -pos;		 
	}
	return res;
}

void add(Int *bit, Int pos, Int val){
	pos++;
	while(pos < 1080000){
		bit[pos] += val;bit[pos] %= MOD;
		pos += pos & -pos;
	}
}


int main(){
	scanf("%I64d%I64d%I64d", &n, &l, &k);
	for(int i = 0;i < n;i++){
		scanf("%I64d", &a[i]);
		nums.push_back(a[i]);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	
	for(int i = 0;i < n;i++){
		a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
		a[i]++;
	}
	add(bit[1], 0, 1);
	Int cnt = (l / n + 1) % MOD;
	for(int i = 0;i < min(l, n * k);i++){
		if(i % n == l % n)cnt--;
		a[i] = a[i % n];
		int id = (i / n) % 2;            
		if(i % n == 0 && i > 0){
			fill(bit[id], bit[id] + n + 20, 0);
		}
		Int p = sum(bit[!id], a[i]);
		res += p * (cnt) % MOD;res %= MOD;
		add(bit[id], a[i], p);
	}
if(res < 0)res += MOD;
	printf("%I64d\n", res);
	return 0;
}