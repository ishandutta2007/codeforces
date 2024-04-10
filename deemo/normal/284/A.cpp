#include<iostream>

using namespace std;

int main(){
	int p;	cin >> p;
	int cnt = 0;
	for (int i = 1; i < p; i++){
		bool fl = 1;
		long long x = i;
		for (int j = 0; j < p - 2; j++, x = (x * i) % p)
			if (x == 1)	fl = 0;
		if (fl)	cnt++;
	}	
	cout << cnt << endl;
	return 0;
}