#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<numeric>
#include<cstdio>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define frist first
#define bulid build
typedef long long ll;
using namespace std;
void work() {
	int c1,c2,c3;
	int a1,a2,a3,a4,a5;
	scanf("%d%d%d",&c1,&c2,&c3);
	scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
	c1 -= a1;
	c2 -= a2;
	c3 -= a3;
	if(c1 < 0 || c2 < 0 || c3 < 0) {
		puts("NO");
		return;
	}
	a4 -= c1;
	a5 -= c2;
	c3 -= max(a4,0) + max(a5,0);
	if(c3 < 0) {
		puts("NO");
		return;
	}
	puts("YES");
	return;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		work();
	}
	return 0;
}
/*
*/