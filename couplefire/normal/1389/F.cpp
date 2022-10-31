#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

template<class T, int SZ> struct LazySeg { // set SZ to a power of 2
	T sum[4*SZ], lazy[4*SZ]; 
	LazySeg() {
		memset(sum,0,sizeof(sum));
		memset(lazy,0,sizeof(lazy));
	}
	void push(int ind, int L, int R) { // modify values for current node
		sum[ind] += lazy[ind]; 
		if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind]; 
		lazy[ind] = 0; // pushed lazy to children
	}
	void pull(int ind) { // recalc values for current node
		sum[ind] = max(sum[2*ind],sum[2*ind+1]); }
	void build() { for(int i = SZ-1; i>=1; i--) pull(i); }
	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc; 
			push(ind,L,R); return;
		}
		int M = (L+R)/2;
		upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
		pull(ind);
	}
	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L+R)/2;
		return max(qsum(lo,hi,2*ind,L,M),qsum(lo,hi,2*ind+1,M+1,R));
	}
};

LazySeg<int, MAXN*2+5> lseg1;
LazySeg<int, MAXN*2+5> lseg2;
map<int, int> mp;
int n;
int dp1[2*MAXN], dp2[2*MAXN];
set<int> coords;
pair<pair<int, int>, int> tempsegs[MAXN];
pair<pair<int, int>, int> segs[MAXN];
vector<int> color1[2*MAXN];
vector<int> color2[2*MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int a, b, color; cin >> a >> b >> color;
        coords.insert(a); coords.insert(b);
        tempsegs[i] = {{a, b}, color};
    }
    int tempcur = 1;
    for(auto i : coords) mp[i] = tempcur++;
    for(int i = 0; i<n; i++) segs[i] = {{mp[tempsegs[i].first.first], mp[tempsegs[i].first.second]}, tempsegs[i].second};
    for(int i = 0; i<n; i++){
        if(segs[i].second == 1) color1[segs[i].first.second].push_back(segs[i].first.first);
        else color2[segs[i].first.second].push_back(segs[i].first.first);
    }
    dp1[0] = 0;
    dp2[0] = 0;
    
    for(int i = 1; i<2*MAXN; i++){
        int max1 = -1000000009;
        int max2 = -1000000009;
        dp1[i] = dp1[i-1];
        dp2[i] = dp2[i-1];
        for(auto j : color1[i]){
            lseg2.upd(0, j-1, 1);
            max1 = max(max1, j);
        }
        for(auto j : color2[i]){
            lseg1.upd(0, j-1, 1);
            max2 = max(max2, j);
        }
        if(max1 > 0) dp1[i] = max(dp1[i], lseg2.qsum(0, max1-1));
        if(max2 > 0) dp2[i] =  max(dp2[i], lseg1.qsum(0, max2-1));

        lseg1.upd(i, i, dp1[i]);
        lseg2.upd(i, i, dp2[i]);

    }

    cout << max(dp1[2*MAXN-1], dp2[2*MAXN-1]) << endl;
}