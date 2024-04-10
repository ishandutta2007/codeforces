//Code By CXY
#include<bits/stdc++.h>
using namespace std;

int T;
int n,x,y,l1,r1,l2,r2;
int ans1,ans2,tmp1,tmp2;

int main () {
	cin >> T;
	while(T--) {
		cin >> n >> x >> y;
		l1 = x - 1,l2 = y - 1;
		r1 = n - x,r2 = n - y;
		ans1 = max(x + y - n,0) + 1;
		ans2 = x + y - 1;
		cout << min(ans1,n) << ' ' << min(ans2,n) << endl;
	}
	return 0;
}