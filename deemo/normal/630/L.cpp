#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e5;

int main(){
	ll n;	cin >> n;
	ll m = 0;
	m += n / 10000;
	m *= 10;
	m += (n / 100) % 10;
	m *= 10;
	m += n % 10;
	m *= 10;
	m += (n/10)%10;
	m *= 10;
	m += (n/1000) % 10;

	

	ll tt = m;
	for (int i = 1; i < 5; i++)
		m = (m * tt) % MOD;

	ll tmp = m;
	int cnt = 0;
	while (tmp){
		cnt++;
		tmp /= 10;
	}
	cnt = 5 - cnt;

	cnt = min(4, cnt);
	for (int i = 0; i < cnt; i++)	cout << "0";


	cout << m << "\n";
	return	0;
}