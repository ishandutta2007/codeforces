#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 200;

int n, d, sum, tsum;
int vec[MAXN];

int main(){
	cin >> n >> d;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		sum += vec[i];
		tsum += vec[i];
		if (i != n - 1)	tsum += 10;
	}
	if (tsum > d){
		cout << -1 << endl;
		return	0;
	}
	int z = d - sum;
	cout << z / 5 << endl;
	return	0;
}