#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main () {
	int n,m,p;
	scanf ("%d %d %d",&n,&m,&p);
	vector<int> a(n), b(m);
	for (auto &au : a) scanf ("%d",&au), au %= p;
	for (auto &au : b) scanf ("%d",&au), au %= p;
	int i = n-1, j = m-1;
	while (!a[i]) --i;
	while (!b[j]) --j;
	printf ("%d\n",i+j);
	return 0;
}