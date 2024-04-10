#include <iostream>
#include <cmath>
typedef long long LL;
using namespace std;

int main(){
	int n;
	double r,R;
	cin >> n;
	cin >> R >> r;
	if(R<r){
		cout << "NO";
		return 0;
	}
	if(R<2*r){
		if(n==1)cout << "YES";
		else cout << "NO";
		return 0;
	}
	double a=asin(r/(R-r));
	if(double(n)*a<3.1415926536)cout <<"YES";
	else cout << "NO";
}