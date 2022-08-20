#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin()
#define e end()
#define lb lower_bound
#define ub upper_bound

#define PI 4*atanl(1)

int n, a1, a2;
ld mina = 2*PI;
vector <pair<pair<ld,int>,pii>> x;

int main() {
	cin >> n;
	x.resize(n);
	F0R(i,n) {
		scanf("%d%d",&x[i].s.f,&x[i].s.s);
		x[i].f.s = i+1;
		x[i].f.f = asinl(x[i].s.s/sqrt(x[i].s.f*x[i].s.f+x[i].s.s*x[i].s.s));
		if (x[i].s.f<0) x[i].f.f = PI-x[i].f.f;
		if (x[i].f.f<0) x[i].f.f += 2*PI;
	}
	sort(x.b,x.e);
	F0R(i,n-1) {
		ld k = x[i+1].f.f-x[i].f.f;
		if (k<mina) {
			mina = k;
			a1 = x[i].f.s, a2 = x[i+1].f.s;
		}
	}
	ld k = x[0].f.f+2*PI-x[n-1].f.f;
	if (k<mina) {
		mina = k;
		a1 = x[0].f.s, a2 = x[n-1].f.s;
	}
	cout << a1 << " " << a2;
	return 0;
}