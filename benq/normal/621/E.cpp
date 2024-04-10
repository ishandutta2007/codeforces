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

int n,b,k,x,v, **a, MOD = 1e9+7;

int** make() {
	int** res = new int*[x];
	F0R(i,x){
		res[i] = new int[x];
		F0R(j,x) res[i][j] = 0;
	}
	return res;
} // makes empty array

int** mult(int** b) {
	int** res = make();
	F0R(i,x) F0R(k,x) F0R(j,x) res[i][j] = (res[i][j]+1LL*a[i][k]*b[k][j])%MOD;
	return res;
}

int** pow(int p) {
	int** ans = make();
	F0R(i,x) ans[i][i] = 1;
	while (p) {
		if (p&1) ans = mult(ans);
		p >>= 1;
		a = mult(a);
	}
	return ans;
}

int main() {
	cin >> n >> b >> k >> x;
	a = make();
	F0R(i,n) {
		cin >> v;
		F0R(j,x) a[j][(10*j+v)%x] ++;
	}
	cout << pow(b)[0][k];
}