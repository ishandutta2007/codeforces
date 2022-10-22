#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int x;
	cin >> x;
	if(x == 4) {
        cout << "4 2";
	}else if(x == 3) {
        cout << "2 2";
	}else if (x == 1){
        cout << -1;
	}else if (x == 2) {
        cout << "2 2";
	}else if (x % 2 == 0 && x > 3){
        cout << x / 2 << ' ' << x / 2;
	}else {
        cout << x - 1 << ' ' << (x - 1) / 2;
	}
}