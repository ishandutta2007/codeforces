#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
ll n,m,k,goal,v;
pii sw[2];
vector<pii> a,b;
vector<pair<ll, pii>> a1,b1;

void prep() {
	scanf("%d",&n), a.resize(n);
	F0R(i,n) scanf("%d",&a[i].f), a[i].s = (i+1);
	scanf("%d",&m), b.resize(m);
	F0R(i,m) scanf("%d",&b[i]), b[i].s = (i+1);
	sort(a.begin(),a.end()), sort(b.begin(),b.end());
	ll sum1 = 0, sum2 = 0;
	F0R(i,n) sum1 += a[i].f;
	F0R(i,m) sum2 += b[i].f;
	goal = sum2-sum1;
	v = abs(sum2-sum1);
}

void query1() {
	int cur2 = 0;
	F0R(i,n) {
		while (cur2<m-2 && 2*b[cur2+1].f <= 2*a[i].f+goal) cur2++;
		ll k1 = abs(2*a[i].f+goal-2*b[cur2].f), k2 = abs(2*a[i].f+goal-2*b[cur2+1].f);
		if (k1 < v) v = k1, sw[0]=mp(a[i].s,0), sw[1] = mp(b[cur2].s,0);
		if (k2 < v) v = k2, sw[0]=mp(a[i].s,0), sw[1] = mp(b[cur2+1].s,0);
	}
}

void query2() {
	F0R(i,n) FOR(j,i+1,n) a1.pb(mp(a[i].f+a[j].f,mp(a[i].s,a[j].s)));
	F0R(i,m) FOR(j,i+1,m) b1.pb(mp(b[i].f+b[j].f,mp(b[i].s,b[j].s)));
	sort(a1.begin(),a1.end()), sort(b1.begin(),b1.end());
	
	int cur2 = 0;
	F0R(i,a1.size()) {
		while (cur2<b1.size()-2 && 2*b1[cur2+1].f <= 2*a1[i].f+goal) cur2++;
		ll k1 = abs(2*a1[i].f+goal-2*b1[cur2].f), k2 = abs(2*a1[i].f+goal-2*b1[cur2+1].f);
		if (k1 < v) v = k1, sw[0]=a1[i].s, sw[1] = b1[cur2].s;
		if (k2 < v) v = k2, sw[0]=a1[i].s, sw[1] = b1[cur2+1].s;
	}
}

void print() {
	cout << v << endl;
	if (sw[0].f == 0) cout << 0;
	else if (sw[0].s == 0)  cout << 1 << endl << sw[0].f << " " << sw[1].f;
	else cout << 2 << endl << sw[0].f << " " << sw[1].f << endl << sw[0].s << " " << sw[1].s;
}

int main() {
	prep();
	query1();
	if (n > 1 && m > 1) query2();
	print();
	return 0;
}