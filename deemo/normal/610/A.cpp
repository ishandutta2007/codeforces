#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	if (n % 2 == 1){
		cout << 0 << endl;
		return 0;
	}
	n/=2;
	int ans = n/2;
	if (n % 2 == 0)	ans--;
	cout << ans << endl;
	return 0;
}