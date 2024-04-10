#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <long long, long long> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second

pii p;
vector<pii> a;
ll n, S; 

bool comp(pii a, pii b) {
	if (a.s != b.s) return (a.s<b.s);
	else return (a.f<b.f);
}

// fix
bool comp1(pii a, pii b) {
	double a1 = double(a.f-p.f)/sqrt(double(a.f-p.f)*(a.f-p.f)+(a.s-p.s)*(a.s-p.s));
	double b1 = double(b.f-p.f)/sqrt(double(b.f-p.f)*(b.f-p.f)+(b.s-p.s)*(b.s-p.s));
	/*cout << "a " << a.f << " " << a.s << endl;
	cout << "b " << b.f << " " << b.s << endl;
	cout << "c " << a1 << " " << b1 << endl;*/
	return (a1>b1);
}

ll ccw(pii p1, pii p2, pii p3) {
    return (p2.f - p1.f)*(p3.s - p1.s) - (p2.s - p1.s)*(p3.f - p1.f);
}

int convex() {
	a.pb(a[0]);
	int M = 1;
	FOR(i,2,a.size()) {
		while (ccw(a[M-1],a[M],a[i]) <= 0) {
			if (M>1) M--;
			else i++;
		}
		M++;
		swap(a[M],a[i]);
	} 
	return M;
}

double area(pii a, pii b, pii c) {
	return abs(double((b.f-a.f)*(c.s-a.s)-(b.s-a.s)*(c.f-a.f)))/2;
}

void input() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> S; a.resize(n);
	F0R(i,n) cin >> a[i].f >> a[i].s;
	sort(a.begin(),a.end(),comp);
	a.erase(unique(a.begin(),a.end()),a.end());
	
	p = a[0];
	sort(a.begin()+1,a.end(),comp1);
}

void solve() {
	ll M = convex(), A = 0, B = 1, C = 2;
 	ll bA = A, bB= B, bC= C;
	while (1) {
		while(1) {
    		while (area(a[A], a[B], a[C]) <= area(a[A], a[B], a[(C+1)%M])) C = (C+1)%M;
     		if (area(a[A], a[B], a[C]) <= area(a[A], a[(B+1)%M], a[C])) {
     			B = (B+1)%M;
       			continue;
     		} else break;
		}
   		if (area(a[A], a[B], a[C]) > area(a[bA], a[bB], a[bC])) {
   			bA = A, bB = B, bC = C;
   		}
		A = (A+1)%M;
		if (A==B) B = (B+1)%M;
   		if (B==C) C = (C+1)%M;
   		if (A==0) break;
	}
	pii A1 = a[bA], B1 = a[bB], C1 = a[bC];
	cout << (A1.f+B1.f-C1.f) << " " << (A1.s+B1.s-C1.s) << endl;
	cout << (A1.f-B1.f+C1.f) << " " << (A1.s-B1.s+C1.s) << endl;
	cout << (-A1.f+B1.f+C1.f) << " " << (-A1.s+B1.s+C1.s) << endl;
}

int main() {
	input();
	solve();
}