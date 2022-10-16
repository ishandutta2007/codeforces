#include <iostream>

using namespace std;

int main()
{
	int n, i, j;
	cin >> n;
	for(i=19, j=0;j<n;i++) {
		int ds = 0, cpi = i;
		while(cpi) {
			ds += cpi % 10;
			cpi /= 10;
		}
		if(ds == 10) j++;
	}
	cout << i-1 << endl;
}