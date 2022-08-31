/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

const int SZ = 1<<18;
const int MAX = 20000000;

pair<ll,ll> val[MAX], lazy[MAX];
int L[MAX], R[MAX], nex = 2;
int loc[2*SZ];
 
void build(int id = 1, int l = 0, int r = SZ - 1) {
	int m = (l+r)/2;
	if (l == r) return;
	L[id] = nex++, R[id] = nex++;
	build(L[id], l, m);
	build(R[id], m + 1, r);
}
 
int update(int x, int y , pair<ll,ll> z, int id, int l = 0, int r = SZ - 1){
	if (l > y || r < x) return id;
	int ID = nex++;
	if (l >= x && r <= y){
		lazy[ID] = {z.f+lazy[id].f,z.s+lazy[id].s};
		val[ID] = {z.f+val[id].f,z.s+val[id].s};
		L[ID] = L[id], R[ID] = R[id];
		return ID;
	}
	
	int m = (l+r)/2;
	if (lazy[id] != mp(0LL,0LL)){
		L[id] = update(l, r, lazy[id], L[id], l, m); // continue updating left, it will change L[id] to new one 
		R[id] = update(l, r, lazy[id], R[id], m + 1, r);
		lazy[id] = mp(0LL,0LL);
	}

	L[ID] = update(x, y, z, L[id], l, m);
	R[ID] = update(x, y, z, R[id], m + 1, r);
	val[ID] = mp(0LL,0LL);
	return ID;
}
 
pair<ll,ll> query(int x,  int id, int l = 0, int r = SZ - 1) {
	if (l == x && r == x) return val[id];
	
	int m = (l+r)/2;
	pair<ll,ll> p;
	if (x <= m) p = query(x, L[id], l, m);
	else p = query(x, R[id], m + 1, r);
	
	return {p.f+lazy[id].f,p.s+lazy[id].s};
}
 
int n,m;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n; loc[0] = 1;
    build();
    F0R(i,n) {
        ll x1, x2, y1, a, b, y2; cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        loc[3*i+1] = update(0,x1,mp(0LL,y1),loc[3*i]);
        loc[3*i+2] = update(x1+1,x2,mp(a,b),loc[3*i+1]);
        loc[3*i+3] = update(x2+1,SZ-1,mp(0LL,y2),loc[3*i+2]);
    }
    cin >> m;
    ll lst = 0;
    F0R(i,m) {
        ll l,r,x; cin >> l >> r >> x;
        x = (x+lst) % 1000000000;
        x = (x+1000000000) % 1000000000;
        x = min(x,(ll)SZ-1);
        pair<ll,ll> a = query(x,loc[3*r]), b = query(x,loc[3*(l-1)]);
        a.f -= b.f, a.s -= b.s;
        lst = a.f*x+a.s;
        cout << lst << "\n";
    }
}