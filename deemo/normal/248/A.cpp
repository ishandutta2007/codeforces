#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;	cin >> n;
	int c1 = 0, c2 = 0;
	int tn = n;
	while (n--){
		int a, b;	cin >> a >> b;
		if (a == 0)	c1++;
		if (b == 0)	c2++;
	}
	n = tn;
	cout << min(c1, n - c1) + min(c2, n - c2) << endl;
	return 0;
}