#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int aa = a ^ b, bb = c | d, cc = b & c, dd = a ^ d;
	int aaa = aa & bb, bbb = cc | dd;
	int aaaa = aaa ^ bbb;
	printf("%d\n", aaaa);
}