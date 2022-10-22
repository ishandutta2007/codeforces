//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;

int T,n,L,R,vl,vr;
int a[MAXN];

int main () {
	cin >> T;
	while(T--) {
		cin >> n;
		for(register int i = 1;i <= n; ++i)
			cin >> a[i];
		L = 1,R = n,vl = vr = 0;
		while(L < R && L < n && R > 1) {
			int cnt = 0;
			if(L < R && a[L + 1] > vl) 
				vl++,L++,cnt++;
			if(L < R && a[R - 1] > vr)
				vr++,R--,cnt++;
			if(!cnt) break;
		}
		if(L < R) {puts("No"); continue;}
		if(n & 1) {puts("Yes"); continue;}
		if(vl != vr) {puts("Yes"); continue;}
		if(a[L] > vl || a[R] > vr) {puts("Yes"); continue;}
		puts("No");
	}
	return 0;
}