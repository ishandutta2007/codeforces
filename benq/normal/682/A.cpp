#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=a; i<b; i++)
long long n,m, a[5],b[5];
	
int main() {
	cin >> n >> m;
	FOR(i,1,n+1) a[i % 5] ++;
	FOR(i,1,m+1) b[i % 5] ++;
	cout << (a[0]*b[0]+a[1]*b[4]+a[2]*b[3]+a[3]*b[2]+a[4]*b[1]);
}