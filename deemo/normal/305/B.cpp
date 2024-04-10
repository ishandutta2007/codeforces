#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll max_n = 200;

ll f[max_n], g[max_n];
ll p, q;
int n;

int main(){
	cin >> p >> q;
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> f[i];
	if (n > 1 && f[n - 1] == 1){
		n--;
		f[n - 1]++;
	}		
	
	for (int i = 0; i < n; i++){
		g[i] = p/q;
		p %= q;
		if (p == 0)	break;
		swap(p, q);
	}

	if (p != 0){
		cout << "NO" << endl;
		return 0;
	}

	bool fl = 0;
	for (int i = 0; i < n; i++)
		if (f[i] != g[i])	fl = 1;
	if (fl){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}