#include<iostream>

using namespace std;

int gs(int n){
	int ret = 365;
	if (n % 400 == 0 || (n % 4 == 0 && n % 100))
		ret++;
	return ret;
}

int main(){
	int n;	cin >> n;
	int m = n % 7;
	int cur = m, sz, tsz = 365;

	if (n % 400 == 0 || (n % 4 == 0 && n % 100))
		tsz++;

	do{
		sz = 365;
		if (n % 400 == 0 || (n % 4 == 0 && n % 100))
			sz++;
		cur = (cur + sz) % 7;
		n++;
	}while (cur != m || (gs(n) != tsz));
	cout << n << endl;
	return 0;
}