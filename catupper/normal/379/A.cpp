#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int res = 0;
	int ok = a;
	int out = 0;
	while(ok){
		res += ok;
		out += ok;
		ok = out / b;
		out %= b;
	}
	cout << res << endl;
	return 0;	
}