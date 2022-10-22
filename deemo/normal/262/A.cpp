#include<iostream>

using namespace std;

int get(int x){
	int ret = 0;
	while (x){
		if (x % 10 == 4 || x % 10 == 7)	ret++;
		x /= 10;
	}
	return	ret;
}

int main(){
	int n, k;	cin >> n >> k;
	int ans = 0;
	while (n--){
		int x;	cin >> x;
		if (get(x) <= k)	ans++;
	}
	cout << ans << endl;
	return 0;
}