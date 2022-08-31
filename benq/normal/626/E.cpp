#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

int n, el[200000],sz1, mid1;
ll cum[200001];
double ans1 = -1;

ll sum(int lo, int high) {
	if (lo == 0) return cum[high];
	else return cum[high]-cum[lo-1];
}

int query1(int mid, int lo, int hi) {
	if (lo == hi) return lo;
	int k = (lo+hi)/2;
	ld av = (ld)(sum(mid-k,mid)+sum(n-k,n-1))/(2*k+1);
	if ((ld)(el[mid-k-1]+el[n-k-1])/2 < av) return query1(mid,lo,k);
	else return query1(mid,k+1,hi);
}

int query2(int mid, int lo, int hi) {
	if (lo == hi) return lo;
	int k = (lo+hi)/2;
	ld av = (ld)(sum(mid-k,mid+1)+sum(n-k,n-1))/(2*k+2);
	if ((ld)(el[mid-k-1]+el[n-k-1])/2 < av) return query2(mid,lo,k);
	else return query2(mid,k+1,hi);
}

void print() {
	cout << sz1 << endl;
	if (sz1 % 2 == 0) {
		cout << el[mid1] << " " << el[mid1+1] << " ";
		FOR(i,1,sz1/2) cout << el[mid1-i] << " " << el[n-i] << " ";
	} else {
		cout << el[mid1] << " ";
		FOR(i,1,(sz1+1)/2) cout << el[mid1-i] << " " << el[n-i] << " ";
	}
}

int main() {
	scanf("%d",&n);
	F0R(i,n) scanf("%d",&el[i]);
	sort(el,el+n);
	cum[0] = el[0];
	FOR(i,1,n) cum[i] = cum[i-1]+el[i];
	
	FOR(i,1,n-1) {
		int x = query1(i,1,min(i,n-1-i));
		ld y = (ld)(sum(i-x,i)+sum(n-x,n-1))/(2*x+1)-el[i];
		if (y>ans1) mid1 = i, sz1 = 2*x+1, ans1 = y;
	}
	FOR(i,1,n-2) {
		int x = query2(i,1,min(i,n-2-i));
		ld y = (ld)(sum(i-x,i+1)+sum(n-x,n-1))/(2*x+2)-(ld)(el[i]+el[i+1])/2;
		if (y>ans1) mid1 = i, sz1 = 2*x+2, ans1 = y;
	}
	if (ans1<0) mid1 = 0, sz1 = 1;
	print();
}