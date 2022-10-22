#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int>	vec(n);
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		if (vec[i] == 1)	c1++;
		else	c2++;
	}

	while (q--){
		int l, r;	cin >> l >> r;	l--;
		if ((r - l) % 2 == 1){
			cout << 0 << endl;
			continue;
		}
		int x = (r - l)/ 2;
		if (c1 >= x && c2 >= x)	cout << 1 << endl;
		else	cout << 0 << endl;
	}
	
	return 0;
}