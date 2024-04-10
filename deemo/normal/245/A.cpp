#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;	cin >> n;
	int x = 0, y = 0, xx = 0, yy = 0;
	while (n--){
		int t, a, b;	cin >> t >>a >> b;
		if (t == 1){
			x += a;
			xx += b;
		}
		else{
			y += a;
			yy += b;
		}
	}
	if (x >= xx)
		cout << "LIVE\n";
	else
		cout << "DEAD\n";

	if (y >= yy)
		cout << "LIVE\n";
	else
		cout << "DEAD\n";
	return 0;
}