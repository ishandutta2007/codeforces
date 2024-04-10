#include <iostream>
#include <cmath>
typedef long long LL;
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n==2){
		cout << -1;
		return 0;
	}
	//2*3 4*3 8*3 .....  2^{n-1}*5 5*3
	LL pot=2;
	for(int i=1;i<n-1;i++){
		cout << 3*pot << endl;
		pot*=2;
	}
	cout << 5*pot << endl;
	cout << 15 << endl;
}