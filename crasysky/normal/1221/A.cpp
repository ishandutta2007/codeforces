#include <iostream>
using namespace std;

int main(){
	int q;
	cin >> q;
	while (q --){
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; ++ i){
			int x;
			cin >> x;
			if (x <= 2048)
				sum += x;
		}
		if (sum >= 2048)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}