#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define MOD 1000000007

typedef long long Int;
set<Int> nums;
Int u[1080000], p, k;
Int cnt[1080000];
Int r(Int x){
	if(u[x] == x)return x;
	return u[x] = r(u[x]);
}

Int unite(Int x, Int y){
	x = r(x);
	y = r(y);
	u[x] = y;
}

int main(){
	for(Int i = 0;i < 1080000;i++)u[i] = i;
	cin >> p >> k;
	for(Int i = 0;i < p;i++){
		unite(i, (i * k) % p);
	}
	for(Int i = 0;i < p;i++){
		nums.insert(r(i));
	}
	Int res = 1;
	for(Int i = 1;i < nums.size();i++){
		res *= p;
		res %= MOD;
	}
	if(k == 1)res *= p;
	
	if(k == 0){
		res = 1;
		for(int i = 1;i < p;i++){
			res *= p;
			res %= MOD;
		}
	}
	
	cout << res%MOD << endl;
	return 0;	
}