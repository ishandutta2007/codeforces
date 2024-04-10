#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int n;	cin >> n;
	int s = 0;
	int t = n;
	while (n--){
		int temp;	cin >> temp;
		s += temp;
	}
	n = t;
	int ans = 0;
	for (int i = 1; i < 6; i++)
		if (((s + i) % (n + 1)) != 1)	ans++;
	cout << ans << endl;
	return 0;
}