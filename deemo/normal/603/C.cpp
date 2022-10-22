#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 20;

int n, k;
int tz[10] = {0, 1, 0, 1, 2, 0}; 
int tt[10] = {0, 1, 2, 0, 1, 0};

int get(int x){
	if (k % 2 == 0){
		if (x < 6)
			return	tt[x];
		if (x % 2 == 0)
			return	1;
		return	0;
	}
	else{
		if (x < 6)
			return	tz[x];
		if (x % 2 == 1)
			return	0;
		int a = get(x/ 2), b = get(x - 1);
		if (a > b)	swap(a, b);
		if (a == 0 && b == 1)
			return	2;
		if (a == 0)
			return	1;
		return	0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++){
		int temp;	cin >> temp;
		temp = get(temp);
		ans ^= temp;
	}
	if (ans == 0)
		cout << "Nicky\n";
	else
		cout << "Kevin\n";
	return 0;
}