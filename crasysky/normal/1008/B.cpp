#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int last = 2000000000;
	bool flag = false;
	for (int i = 1; i <= n; ++ i){
		int x, y;
		scanf("%d %d", &x, &y);
		if (flag)
			continue;
		if (x < y)
			swap(x, y);
		if (x <= last)
			last = x;
		else{
			if (y <= last)
				last = y;
			else
				flag = true;
		}
	}
	if (flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}