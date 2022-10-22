#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a, b, c;	cin >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i < 3; i++){
		int aa = a - i, bb = b - i, cc = c - i;
		int ret = i;
		if (aa < 0 || bb < 0 || cc < 0)	continue;
		ret += aa/3;
		ret += bb/3;
		ret += cc/3;
		ans = max(ans, ret);
	}
	cout << ans << endl;
	return 0;
}