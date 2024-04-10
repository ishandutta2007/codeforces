#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	double res=0;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		res+=x;
	}
	res=res/(double(n));
	cout.precision(20);
	cout << res;
}