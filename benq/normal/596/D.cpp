#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b) for (int i=a; i<b; i++)

int n,h,x,l,u,gn, t[4][2001][2001], pos[2002];
double p, values[4][2001][2001];

double dp(int prevl, int prevr, int lower, int upper) {
	if (t[2*prevl+prevr][lower][upper])return values[2*prevl+prevr][lower][upper];
	int minp=pos[lower-1], maxp=pos[upper+1];
	if (prevl == 1) minp += h;
	if (prevr == 0) maxp -= h;
	double avg = 0;
	
	if (lower == upper) {
		if (minp>pos[lower]) {
			avg += (pos[lower]+h)-minp;
			if (pos[lower]+h>maxp) avg -= (pos[lower]+h-maxp);
		} else if (maxp<pos[lower]) {
			avg += (maxp-(pos[lower]-h));
			if (pos[lower]-h<minp) avg -= (minp+h-pos[lower]);
		} else {
			avg += h;
			if (pos[lower]-h<minp) avg -= p*(h+minp-pos[lower]);
			if (maxp<pos[lower]+h) avg -= (1-p)*(h+pos[lower]-maxp);
		}
	} else {
		if (minp>pos[lower]) avg = pos[lower]+h-minp+dp(prevl,prevr,lower+1,upper);
		else if (maxp<pos[upper]) avg = maxp-(pos[upper]-h)+dp(prevl,prevr,lower,upper-1);
		else {
			avg += p/2*(min(h,pos[lower]-minp)+dp(0,prevr,lower+1,upper));
			avg += (1-p)/2*(h+dp(1,prevr,lower+1,upper));
			avg += p/2*(h+dp(prevl,0,lower,upper-1));
			avg += (1-p)/2*(min(h,maxp-pos[upper])+dp(prevl,1,lower,upper-1));
		}
	}
	t[2*prevl+prevr][lower][upper] = 1;
	values[2*prevl+prevr][lower][upper] = avg;
	return avg;
}

int main() {
	scanf("%d%d",&n,&h); cin >> p;
	pos[0] = -200000000;
	FOR(i,1,n+1) scanf("%d",&pos[i]);
	pos[n+1] = 200000000;
	sort(pos,pos+n+2);
	cout << fixed << setprecision(10) << dp(0,1,1,n);
	return 0;
}