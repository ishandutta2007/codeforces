#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n, m;	cin >> n >> m;
	int i;
	for (i = 1; ; i++){
		if (n == 0)	break;
		n--;
		if (i % m == 0)	n++;
	}
	i--;
	cout << i << endl;
	return	0;
}