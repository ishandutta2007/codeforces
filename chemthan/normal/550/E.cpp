#include <iostream>
#include <vector>
using namespace std;
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORd(i, n) for(int i = n - 1; i >= 0; i--)
int n;
bool a[100000]; int le[100000], ri[100000]; vector<int> izero;

void main() {
	ms(le, 0); ms(ri, 0); cin>>n; FOR(i, n) cin>>a[i];
	if (a[n - 1] == 1) {cout<<"NO"; return;} int cnt = 0, k = -1;
	FORd(i, n) {if (a[i] == 0) {cnt++; izero.push_back(i); if (k > -1) {ri[k + 1]++; le[i + 1]++; k = -1;}} else {if (cnt & 1) break; if (k == -1) k = i;} if (cnt == 3) {le[izero[2]]++; ri[izero[1]]++; break;}}
	if (cnt & 1) {cout<<"YES\n"; FOR(i, n) {if (i > 0) cout<<"->"; while (le[i]--) cout<<"("; cout<<a[i]; while (ri[i]--) cout<<")";}} else cout<<"NO";
}