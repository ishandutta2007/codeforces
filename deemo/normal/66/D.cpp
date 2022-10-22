#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 50 + 3;

int n, ans[MAXN];

bool pr(int x){
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)	return	false;
	return	true;
}

int main(){
	cin >> n;
	if (n < 3){
		cout << "-1\n";
		return	0;
	}
	
	ans[0] = 15;
	ans[1] = 35;
	ans[2] = 21;
	
	int z = 15 * 35 * 21;
	for (int i = 3; i < n; i++)
		ans[i] = i * z;

	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
	return	0;
}