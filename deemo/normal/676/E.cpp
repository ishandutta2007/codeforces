#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll MOD4 = 12345679;
//const ll MOD5 = 1e15 + 9;

stringstream ss;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;	cin >> n >> k;
	int cnt = 0;
	ll sm = 0, z = 1, sm2 = 0, z2 = 1, sm3 = 0, z3 = 1, sm4 = 0, z4 = 1, sm5 = 0, z5 = 1;
	n++;
	bool turn = 0;
	int tn = n;
	ll gg = 1e9;
	while (n--){
		string s;	cin >> s;
		if (s[0] == '?')
			cnt++;
		else{
			turn = !turn;
			ss.clear();
			ss << s;
			ll x;	ss >> x;
			if (n + 1 == tn)	
				gg = x;
			sm = (sm + z * x % MOD + MOD) % MOD;
			sm2 = (sm2 + z2 * x % MOD2 + MOD2) % MOD2;
			sm3 += z3 * x;
			sm4 = (sm4 + z4 * x % MOD4 + MOD4) % MOD4;
		//	sm5 = (sm5 + z5 * x % MOD5 + MOD5) % MOD5;
		}
		z = (z * k % MOD + MOD) % MOD;
		z2 = (z2 * k % MOD2 + MOD2) % MOD2;
		z3 *= k;
		z4 = (z4 * k % MOD4 + MOD4) % MOD4;
		//z5 = (z5 * k % MOD5 + MOD5) % MOD5;
	}
	bool fail = 0;
	if (cnt){
		if (k){
			if (cnt % 2 == 0)	turn = !turn;
			if (!turn)	fail = 1;
		}
		else{
			if (gg > 1e8){//not set
				if (!turn)	fail = 1;
			}
			else{//set
				if (gg)
					fail = 1;
			}
		}
	}
	else
		fail = sm | sm2 | sm3 | sm4 | sm5;

	if (fail)
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
}