#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;
#define MOD 1000000007
              
Int h, w, n, r, c;
vector<P> ps;
Int odd[2160], even[2160], res;

Int fact[216000], rfact[216000];

Int C(Int a, Int b){
	return fact[a] * rfact[a-b] % MOD * rfact[b] % MOD;
}

Int solve(Int a, Int b){
	return C(a+b,b);
}

Int po(Int a, Int n){
	if(n == 0)return 1;
	Int res = po(a, n / 2);
	res *= res;res %= MOD;
	if(n % 2)res *= a;
	return res % MOD;
}

int main(){
	
	for(int i = 0;i < 216000;i++){
		if(i < 2)fact[i] = 1;
		else fact[i] = fact[i - 1] * i % MOD;
	}
	for(int i = 0;i < 216000;i++){
		rfact[i] = po(fact[i], MOD - 2);
	}

	cin >> h >> w >> n;
	for(int i = 0;i < n;i++){
		cin >> r >> c;
		ps.push_back(P(r, c));
	}
	sort(ps.begin(), ps.end());
	for(int i = 0;i < n;i++){
		odd[i] += solve(ps[i].first-1, ps[i].second-1);
		odd[i] %= MOD;
		for(int j = i + 1;j < n;j++){
			if(ps[i].first > ps[j].first || ps[i].second > ps[j].second)continue;
			odd[j] += even[i] * solve(ps[j].first - ps[i].first, ps[j].second - ps[i].second);
			even[j] += odd[i] * solve(ps[j].first - ps[i].first, ps[j].second - ps[i].second);
			odd[j] %= MOD;
			even[j] %= MOD;
		}
		res += odd[i] * solve(h - ps[i].first, w - ps[i].second);
		res -= even[i] * solve(h - ps[i].first, w - ps[i].second);
		res %= MOD;
//		cout << odd[i] << " "<< even[i] << endl;
	}
	res = solve(h-1, w-1) - res; res %= MOD;
	if(res < 0)res += MOD;
	cout << res << endl;
/*	cout << solve(15, 16) << endl;
	cout << solve(99, 88) << endl;
	cout << solve(84, 72) << endl;
	cout << solve(83, 73) << endl;*/
	return 0;
}