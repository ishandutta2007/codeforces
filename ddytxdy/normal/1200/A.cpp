#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+50;
int a[10], n; char s[N];
void L() {
	for (int i = 0; i < 10; i++)if (!a[i]) { a[i] = 1; return; }
}
void R() {
	for (int i = 9; i >=0; i--)if (!a[i]) { a[i] = 1; return; }
}
int main(){
	scanf("%d%s", &n,s+1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'L')L();
		else if (s[i] == 'R')R();
		else a[s[i] - '0'] = 0;
	}
	for (int i = 0; i < 10; i++)printf("%d", a[i]);
	return 0;
}