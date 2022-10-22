#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 20;

int n, k;
int vec[MAXN];
ll sum;
int c1, c2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		sum += vec[i];
		if (vec[i] % 2)	
			c1++;
		else	c2++;
	}
	if (k == n){
		if (sum % 2 == 0)
			cout << "Daenerys\n";
		else
			cout << "Stannis\n";
		return 0;
	}
	n -= k;
	int x = n/2 + bool(n % 2 == 1), y = n/2;

	if (y >= c1)
		cout << "Daenerys\n";
	else if (y >= c2 && k % 2 == 0)
		cout << "Daenerys\n";
	else if (x >= c2 && k % 2 == 1)
		cout << "Stannis\n";
	else{
		if (n % 2 == 0)
			cout << "Daenerys\n";
		else
			cout << "Stannis\n";
	}
	return 0;
}