#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, h;	cin >> n >> h;
	int ans = n;
	while (n--){
		int x;	cin >> x;
		if (x > h)	ans++;
	}
	cout << ans << endl;
	return 0;
}