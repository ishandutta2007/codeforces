#include<iostream>
#include<algorithm>

using namespace std;

int n, k;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int l = 1, r = n;
	
	for (int i = 0; i < k; i++){
		if (i % 2 == 0)
			cout << l++ << " ";
		else
			cout << r-- << " ";
	}
	
	if (k % 2 == 0)
		for (int i = r; i >= l; i--)
			cout << i << " ";
	else
		for (int i = l; i <= r; i++)
			cout << i << " ";
	cout << "\n";
	return	0;	
}