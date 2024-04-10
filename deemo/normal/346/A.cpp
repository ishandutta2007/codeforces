#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;	cin >> n;
	int maxi = 0, g = -1, tt = n;
	while(n--){
		int temp;	cin >> temp;
		if (g==-1)
			g = temp;
		else
			g = __gcd(g, temp);
		maxi = max(maxi, temp);
	}
	int t = maxi / g;
	t -= tt;
	if (t % 2 == 0)
		cout << "Bob\n";
	else
		cout << "Alice\n";
	return 0;
}