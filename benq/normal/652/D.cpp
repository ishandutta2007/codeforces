#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
const int MAXN = 300000;
pair<int,pii> k[MAXN];
int tree[MAXN], ans[MAXN], A[MAXN], B[MAXN];

ll read(int idx){
	ll sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
 	}
 	return sum;
}
 
void update(int idx ,ll val){
 	while (idx <= MAXN){
  		tree[idx] += val;
  		idx += (idx & -idx);
 	}
}

bool cmp(pair<int,pii> x, pair<int,pii> y) {
	if (x.s.f < y.s.f) return true;
	return false;
}

int main() {
	int n;
	cin >> n;
	F0R(i,n) {
		int a,b;
		scanf("%d%d", &a, &b);
		k[i] = mp(i,mp(a,b));
	}
	sort(k,k+n,cmp);
	F0R(i,n) B[i] = A[i] = k[i].s.s;

    memset(tree, 0, sizeof(tree)); 
    sort(B, B + n);
    F0R(i,n) {
    	int rank = int(lower_bound(B, B + n, A[i]) - B);
        A[i] = rank + 1;
    }
    for(int i = n - 1; i >= 0; --i) {
        ll x = read(A[i] - 1);
        ans[k[i].f] = x;
        update(A[i], 1);
    }
    F0R(i,n) cout << ans[i] << endl;
	return 0;
}