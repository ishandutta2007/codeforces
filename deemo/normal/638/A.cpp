#include<iostream>

using namespace std;

int main(){
	int ans = 1, cur = 1;
	int n, x;	cin >> n >> x;
	while (cur != x && n - cur + 1 != x)	cur += 2, ans++;
	cout << ans << "\n";
	return	0;		
}