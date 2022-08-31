#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

int n, t, **m, **ans, a[100], init[100], seg[1<<10], MOD = 1000000007;

int** make() {
    int** ans = new int*[n];
    F0R(i,n) {
        ans[i] = new int[n];
        F0R(j,n) ans[i][j] = 0;
    }
    return ans;
}

int** mult(int **x, int **y) {
    int **z = make();
    F0R(i,n) F0R(j,n) F0R(k,n) {
        if (a[i]>a[j]) z[i][j] = -MOD;
        else z[i][j] = max(z[i][j], x[i][k]+y[k][j]);
    }
    return z;
}

void modify(int p, int value) {  // set value at position p
  for (seg[p += 512] = value; p > 1; p >>= 1) seg[p>>1] = max(seg[p],seg[p^1]);
}

int query(int l, int r) { 
  int res = 0;
  for (l += 512, r += 512; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,seg[l++]);
    if (r&1) res = max(res,seg[--r]);
  }
  return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> t;
    F0R(i,n) {
    	cin >> a[i];
    	init[i] = query(1,a[i]+1)+1;
    	modify(a[i],init[i]);
    }
    m = make(), ans = make();
    F0R(i,n) {
    	memset(seg, 0, sizeof seg);
    	FOR(j,i+1,2*n) {
    		if (a[j % n] >= a[i]) {
    			int x = query(a[i], a[j % n]+1)+1;
    			modify(a[j % n], x);
    			if (j >= n) m[i][j % n] = x;
    		} else if (j >= n) m[i][j % n] = -MOD;
    	}
    }
    /*F0R(i,n) {
    	F0R(j,n) cout << m[i][j] << " ";
    	cout << "\n";
    }
    cout << "\n";*/
    t--; bool f = 0;
    if (t == 0) {
    	int z = 0;
    	F0R(i,n) z = max(z,init[i]);
    	cout << z; return 0;
    }
    while (t) {
    	if (t % 2) {
    		if (f == 0) f = 1, ans = m;
    		else ans = mult(ans,m);
    	}
    	m = mult(m,m);
    	t /= 2;
    }
    int z = 0;
    F0R(i,n) F0R(j,n) z = max(ans[i][j]+init[i],z);
    cout << z;
}