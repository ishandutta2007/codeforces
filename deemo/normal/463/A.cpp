#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n, s;	cin >> n >> s;
	int ans = -1;
	while (n--){
		int a, b;	cin >> a >> b;
		if (a > s)	continue;
		if (a == s && b)	continue;
		if (b)
			ans = max(ans, 100 - b);
		else
			ans = max(ans, 0);
	}
	cout << ans << endl;
	return	0;
}