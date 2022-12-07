#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
string res;
bool calc(int num0, int num1, int a00, int a01, int a10, int a11) {
	if(num0 ==0 && num1 == 0 || num0 * (num0 - 1) != a00 * 2 || num1 * (num1 - 1) != a11 * 2 || a01 + a10 != num0 * num1) {
		return false;
	}else {
		res.clear();	
		while(num0 || num1) {
			while(num1 && a10 >= num0) {
				res.push_back('1');
				num1--;
				a10 -= num0;
			}
			if(num0) {
				res.push_back('0');
				num0--;
			}
		}
		return true;
	}
}
int main() {
	int a00, a01, a10, a11;
	scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
	int num0(sqrt(a00 * 2) + 1);
	int num1(sqrt(a11 * 2) + 1);
	int num0_(a00 ? num0 : 0);
	int num1_(a11 ? num1 : 0);
	if(calc(num0, num1, a00, a01, a10, a11)
	|| calc(num0_, num1, a00, a01, a10, a11)
	|| calc(num0, num1_, a00, a01, a10, a11)
	|| calc(num0_, num1_, a00, a01, a10, a11)) {
		cout << res << endl;
	}else {
		printf("Impossible\n");
	}
	
}