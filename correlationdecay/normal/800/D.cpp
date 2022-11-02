#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#define maxn 1000009
using namespace std;
const int MOD = 1e9 + 7;
const int PHI = 1e9 + 6;
const int MAX = 999999;
int n;
long long f1[maxn], f2[maxn], fc[maxn];
long long bin[maxn];
long long CAL[maxn];
int pw[1 << 10];
int ADD[]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int getnum(int x, int y){
	for(int i = 0; i < y; i++)
		x /= 10;
	return x % 10;	
}

inline int addone(int x, int y){
	return ADD[y] + x;
}


long long solve(int x){
	int tmp[10];
	int tot = 0;
	int num = x;
	for(int i = 0; i < 6; i++){
		if(num % 10 != 9)
			tmp[tot++] = i;
		num /= 10;
	}	
	
	long long val[1 << 7], cnt[1 << 7];
	val[0] = x;
	cnt[0] = 0;
	long long ans = CAL[val[0]];
	for(int i = 1; i < 1 << tot; i++){
		int last = i - (i & -i);
		val[i] = val[last] + ADD[tmp[pw[i & -i]]];
		cnt[i] = cnt[last] + 1;
		if(cnt[i] & 1)
			ans -= CAL[val[i]];
		else
			ans += CAL[val[i]];
		ans %= MOD;
	}
	ans += MOD;
	ans %= MOD;
	return ans;
}




int main(){
	for(int i = 0; i < 10; i++)
		pw[1 << i] = i;
	bin[0] = 1;
	for(int i = 1; i < maxn; i++)
		bin[i] = 2 * bin[i - 1] % MOD;
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		f1[x] = (f1[x] + x) % MOD;
		f2[x] = (f2[x] + 1LL * x * x) % MOD;
		fc[x]++;
	}
	for(int j =0; j < 6; j++){
		for(int i = MAX; i >= 0; i--){
			int x = getnum(i, j);
			if(x == 9)
				continue;
			f1[i] = (f1[i] + f1[addone(i, j)]) % MOD;
			f2[i] = (f2[i] + f2[addone(i, j)]) % MOD;
			fc[i] = (fc[i] + fc[addone(i, j)]) % PHI;
		}
	}
	
	for(int i = 0; i <= MAX; i++){
		long long x = fc[i];
		long long sum1 = f1[i];
		long long sum2 = f2[i];
		long long cur = 0;
		if(sum2) cur += bin[x - 1] * sum2 % MOD;
		//cout << x << " " << sum1 << " " << sum2 << " " << cur << endl;
		sum1 = (sum1 * sum1 - sum2) % MOD;
		if(sum1) cur += bin[x - 2] * sum1 % MOD;
		cur %= MOD;
		cur += MOD;
		cur %= MOD;
		CAL[i] = cur;
	}
	
	//cout << solve(93, fc, MOD) << endl;
	
	//cout << solve(999989) << endl;
	
	long long ans = 0;
	for(int i = MAX; i >= 0; i--){
		long long cur = solve(i);
		//cout << cur * i << endl;
		cur *= i;
		ans ^= cur;
	}
	cout << ans << endl;
	return 0;
}