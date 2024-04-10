#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
	int a, b;	cin >> a >> b;
	if (a < b){
		cout << 0 << "\n";
		return	0;
	}
	if (a == b){
		cout << "infinity\n";
		return	0;
	}
	a -= b;
	int cnt = 0;
	for (int i = 1; i * i <= a; i++)
		if (a % i == 0){
			if (i > b)	cnt++;
			if (i * i != a && a/i > b)	cnt++;
		}
	cout << cnt << "\n";
	return	0;
}