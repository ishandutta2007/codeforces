#include<iostream>
#include<algorithm>

using namespace std;
long long n, k;

int main(){
	cin >> n >> k;
	cout << (6 * n - 1) * k << endl;
	for(int i = 0;i < n;i++){
		long long tmp = 6 * i;
		cout << (tmp + 1) * k << " "
		     << (tmp + 2) * k << " "
			 << (tmp + 3) * k << " "
			 << (tmp + 5) * k << endl;
	}
	return 0;
}