#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; i++)
#define sz(a) int(a.size())
#define mp(a, b) make_pair(a, b)
#define re return
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main() {
   ll a, b, kx[4] = {-1, +1, -1, +1}, ky[4] = {1, 1, -1, -1};
   cin >> a >> b;
   vector<int> ax, ay, by, bx;
   for (int i = 1; i <= max(a, b); i++) {
  	for (int j = 1; j <= max(a, b); j++) {
	    if (i * i + j * j == a * a) {
		 ax.push_back(i); 
                ay.push_back(j);
	    }
	    if (i * i + j * j == b * b) {
		bx.push_back(i);
		by.push_back(j);
	    }
	}
  }
  forn (i, sz(ax)) 
 	forn (j, sz(bx))  
	    forn (k, 4)
		forn (p, 4)
		  if ((ax[i] * kx[k] - bx[j] * kx[p]) * (ax[i] * kx[k] - bx[j] * kx[p]) +
                     (ay[i] * ky[k] - by[j] * ky[p]) * (ay[i] * ky[k] - by[j] * ky[p]) == a * a + b * b && 
			 ax[i] * kx[k] !=  bx[j] * kx[p] && ay[i] * ky[k] != by[j] * ky[p]) {
			cout << "YES\n";
		 	cout << 0 << " " << 0 << "\n";   
			cout << ax[i] * kx[k] << " " << ay[i] * ky[k] << "\n";
			cout << bx[j] * kx[p] << " " << by[j] * ky[p] << "\n";
			re 0;
	 }
   cout << "NO\n";	
   return 0;	
}