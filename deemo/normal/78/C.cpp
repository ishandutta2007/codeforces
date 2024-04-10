//Here we go again..

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	int n, m, k;	cin >> n >> m >> k;
	bool fl = 0;
	for (ll i = 1; i * i <= m; i++)
		if (m % i == 0)
			if ((i != m && i >= k) || (i != 1 && m/i >= k))	fl = 1;
		
	
	if (n % 2 == 0)
		cout << "Marsel\n";
	else{
		if (fl)
			cout << "Timur\n";
		else
			cout << "Marsel\n";
	}
	return 0;
}