#include<iostream>
#include<algorithm>

using namespace std;

int f[4320];

int main(){
	int n, k, res = 0;
	cin >> n >> k;
	for(int i = 0;i < n;i++)cin >> f[i];
	for(;n % k;n++)f[n] = 1;
	sort(f, f + n, greater<int>() );
	for(int i = 0;i * k < n;i++){
		res += (f[i * k] - 1) * 2;
	}
	cout << res << endl;
	return 0;
}