#include <iostream>
#include<string>
using namespace std;
long long a, b;
int main() {
	long long res = 0;
	cin >> a >> b;
	while(b){
		res += a / b;
		a %= b;
		swap(a, b);
	}
	cout << res << endl;return 0;
}