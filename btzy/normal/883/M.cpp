#include <bits/stdc++.h>
using namespace std;

int main() {
	int x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;
	int ans = 2*(abs(x1 - x2) + 1) + 2*(abs(y1 - y2) + 1);
	if(x1 == x2 or y1 == y2)	ans += 2;
	cout<<ans<<endl; 
}