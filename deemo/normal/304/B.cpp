#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int f[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int g[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	int a1, a2, a3, b1, b2, b3;
	scanf("%d:%d:%d", &a1, &a2, &a3);	a2--, a3--;
	scanf("%d:%d:%d", &b1, &b2, &b3);	b2--, b3--;

	if (a1 > b1 || (a1 == b1 && a2 > b2) || (a1 == b1 && a2 == b2 && a3 > b3)){
		swap(a1, b1);
		swap(a2, b2);
		swap(a3, b3);
	}
	
	int ans = 0;
	for (; a1 <= b1; a1++){
		bool fl = 0;
		if (a1 % 400 == 0)	fl = 1;
		else	if (a1 % 100 != 0 && a1 % 4 == 0)	fl = 1;

		int z = 11;
		if (a1 == b1)	z = b2;
		for (;a2 <= z ; a2++){
			int x = f[a2] - 1;
			if (fl)	x = g[a2] - 1;
			if (a1 == b1 && a2 == b2)	x = b3;
			
			for (; a3 <= x; a3++)
				ans++;

			a3 = 0;
		}

		a2 = a3 = 0;
	}
	cout << ans -1 << endl;
	return 0;
}