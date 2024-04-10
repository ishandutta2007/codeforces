#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if (n < 4){
		cout << "NO\n";
		return	0;
	}
	if (n % 2 == 0){
		cout << "YES\n";
		cout << "1 * 2 = 2\n";
		cout << "2 * 3 = 6\n";
		cout << "6 * 4 = 24\n";
	}
	if (n % 2 == 1){
		cout << "YES\n";
		cout << "3 + 5 = 8\n";
		cout << "4 - 2 = 2\n";
		cout << "2 + 1 = 3\n";
		cout << "3 * 8 = 24\n";
	}
	
	int i = 5;
	if (n % 2 == 1)	i = 6;
	for (; i <= n; i += 2){
		cout << i + 1 << " - " << i << " = 1\n";
		cout << "24 * 1 = 24\n";
	}
	return	0;
}