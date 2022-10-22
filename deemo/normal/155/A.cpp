#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int n;	cin >> n;
	int mn, mx;	cin >> mn;	mx = mn;
	int ans = 0;
	n--;
	while (n--){
		int x;	cin >> x;
		if (x < mn || x > mx)	ans++;
		mx = max(mx, x);
		mn = min(mn, x);
	}	
	cout << ans << "\n";
	return	0;
}