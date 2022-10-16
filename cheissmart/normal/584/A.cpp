#include <iostream>
#define RP(n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	if(n == 2) {
		for(int i=10;i<100;i++) 
			if(i % t == 0) {
				cout << i;
				break;
			}
			else if(i == 99) cout << -1;
	} else if(n == 1) {
		cout << (t < 10 ? t : -1);
	} else {
		cout << t;
		if(t < 10) RP(n-1) cout << 0;
		else  RP(n-2) cout << 0;
	}
	
}