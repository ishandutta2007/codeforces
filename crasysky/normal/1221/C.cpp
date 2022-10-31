#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	while (T --){
		int a, b, c;
		cin >> a >> b >> c;
		int ans = min(min(a, b), c);
		a -= ans, b -= ans, c -= ans;
		if (a && b)
			ans += min(min(a, b), (a + b) / 3);
		cout << ans << endl;
	}
}