#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int a, b;	cin >> a >> b;
	int ret = 0;
	while (1){
		if (min(a, b) <= 0)	break;
		if (a < b)
			a += 1, b -= 2;
		else
			b++, a -= 2;
		if (min(a, b) < 0)	break;
		ret++;
	}
	cout << ret << "\n";
	return	0;
}