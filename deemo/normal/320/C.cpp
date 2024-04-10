#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int max_n = 200;

string s;
ll d[max_n], save[max_n];

int main(){
	cin >> s;
	save[0] = 1;
	for (int i = 1; i < max_n; i++)
		save[i] = (save[i - 1] * 2) % MOD;
	d[s.size()] = 0;


	for (int i = s.size() - 1; i >= 0; i--){
		if (s[i] == '0')
			d[i] = (d[i + 1] * 2) % MOD;
		else{
			d[i] = (d[i + 1] * 2) % MOD;
			d[i] = (d[i] + save[s.size() - i - 1] * save[s.size() - i - 1]) % MOD;
		}
	}	
	cout << d[0] << endl;
	return 0;
}