#include <bits/stdc++.h>
 
using namespace std;

#define F0R(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;

const int SZ = 1<<19;
 
int sum[SZ], lazy[SZ], n;
ll rev[200010];
map<ll,int> nums;
vector<pair<int,pii>> z;

int comb(int o1, int o2) {
	if (o2 == 0) return o1;
	if (o1 == 0 || o2 == 1 || o2 == 2) return o2;
	if (o1 == 1) return 2;
	if (o1 == 2) return 1;
	return 0;
}

void push(int ind, int low, int high) { // fix
	if (lazy[ind] == 0) return;
	if (lazy[ind] == 1) sum[ind] = high-low+1;	
	else if (lazy[ind] == 2) sum[ind] = 0;
	else sum[ind] = high-low+1-sum[ind];

    if (low != high) {
    	lazy[2*ind] = comb(lazy[2*ind],lazy[ind]);
    	lazy[2*ind+1] = comb(lazy[2*ind+1],lazy[ind]);
    }
    
    lazy[ind] = 0;
}

void pull(int ind) {
    sum[ind] = sum[2*ind]+sum[2*ind+1];
}

int query(int ind, int low, int high) {
	push(ind,low,high);
	if (low == high) return low;
	
	int mid = (low+high)/2;
	push(2*ind,low,mid);
	if (sum[2*ind] != mid-low+1) return query(2*ind,low,mid);
	return query(2*ind+1,mid+1,high);
}

void update(int ind, int low, int high, int L, int R, int type) {
    push(ind,low,high);
    if (high < L || R < low) return;
    if (L <= low && high <= R) {
    	lazy[ind] = type;
    	push(ind,low,high);
        return;
    }
    int mid = (low+high)/2;
    update(2*ind,low,mid,L,R,type);
    update(2*ind+1,mid+1,high,L,R,type);
    pull(ind);
}
 
void input() {
	cin >> n;
	nums[1] = 1;
	F0R(i,n) {
		ll t,l,r; cin >> t >> l >> r;
		nums[l] = nums[r+1] = 1;
		z.pb({t,{l,r}});
	}
	
	int co = 0;
	for (auto a: nums) {
		nums[a.f] = ++co;
		rev[co] = a.f;
	}
}

int main() {
	input();
	for (auto a: z) {
		update(1,1,nums.size(),nums[a.s.f],nums[a.s.s+1]-1,a.f);
		cout << rev[query(1,1,nums.size())] << "\n";
	}
}