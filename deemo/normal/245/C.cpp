#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 10;

int m, vec[MAXN];

int get(int n){
	if (n == 0)	return	0;
	if (vec[n] == 0)	return	get(n - 1);

	if (n % 2 == 1){
		int z = n/2;
		if (z != 0){
			vec[z] = max(0, vec[z] - vec[n]);
			vec[n - 1] = max(0, vec[n - 1] - vec[n]);
			return	get(n - 1) + vec[n];
		}
		return	get(n - 1) + vec[n];
	}
	else{
		int z = n/2;
		vec[z] = max(0, vec[z] - vec[n]);
		return	vec[n] + get(n - 1);
	}
}

int main(){
	cin >> m;
	int sum = 0;
	for (int i = 1; i <= m; i++){
		cin >> vec[i];
		sum += vec[i];
	}
	if (sum == 0){
		cout << 0 << endl;
		return	0;
	}

	if (m < 3 || (m % 2 == 0 && vec[m] != 0)){
		cout << -1 << endl;
		return	0;
	}		

	cout << get(m) << endl;
	return 0;
}