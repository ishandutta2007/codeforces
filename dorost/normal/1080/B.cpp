#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		if (l % 2){
			if (r % 2){
				cout << (r - l) / 2 - r;
			}else{
				cout << (r - l + 1) / 2; 
			}
		}else{
			if(r % 2){
				cout << (l - r - 1) / 2;
			}else{
				cout << (l - r - 1) / 2 + r;
			}
		}
		cout << endl;
	}
}