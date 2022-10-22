//Where are you, hatter?

#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x;	cin >> n >> x;
	n %= 6;
	for (int i = n; i; i--)
		if (i&1){
			if (x == 0 || x == 1)
				x = 1 - x;
		}
		else{
			if (x == 1 || x == 2)
				x = 3 - x;
		}
	cout << x << endl;
	return 0;
}