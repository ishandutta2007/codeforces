#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define mp make_pair
#define pb push_back

double PI = 4*atan(1);

// create a segment tree with lazy propogation
// x coordinates, y coordinates, angle

complex<double> coor[1<<20];
int lazy[1<<20];

complex<double> get(int node) {
	if (lazy[node]) {
		coor[node] = coor[node]*polar(1.0,lazy[node]*PI/180);
		if (node<(1<<19)) {
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	return coor[node];
}

void update(int ind, int L, int R, int low, int high, int inc) {
	coor[ind] = get(ind);
    if (high < L || R < low) return;
    if (low <= L && R <= high) {
        coor[ind] = coor[ind]*polar(1.0,inc*PI/180);
        if (L != R) lazy[2*ind] += inc, lazy[2*ind+1] += inc;
        return;
    }
    int M = (L+R)/2;
    update(2*ind,L,M,low,high,inc);
    update(2*ind+1,M+1,R,low,high,inc);
    coor[ind] = coor[2*ind]+coor[2*ind+1];
}

void propogate(int node, int inc) {
	coor[node] += inc/sqrt(norm(coor[node]))*coor[node];
	node /= 2;
	while (node) {
		coor[node] = get(2*node)+get(2*node+1);
		node /= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m; cin >> n >> m;
	FOR(i,1,n+1) coor[i+(1<<19)-1] = polar(1.0,0.0);
	for (int i = (1<<19)-1; i > 0; --i) coor[i] = coor[2*i]+coor[2*i+1];
	cout << fixed << setprecision(9);
	F0R(i,m) {
		int x,y,z; cin >> x >> y >> z;
		if (x == 1) propogate(y+(1<<19)-1,z);
		else update(1,1,1<<19,y,1<<19,360-z); // rotate segment y & everything after by z degrees
		cout << get(1).real() << " " << get(1).imag() << "\n";
	}
}