#include <bits/stdc++.h>
using namespace std;
int ret[1<<19];
void uin (int &a, int b) {if (b < a) a = b;}
bool mx;
vector<int> cur;
void rec (int l, int bit, int L, int R) { 
	if (bit < 0) {
		ret[l] = cur[L];
		return;
	}
	int pos = R+1;
	for (int i = R; i >= L; i--) if (cur[i] >> bit & 1) pos = i;
	if (pos == R+1) {
		rec(l,bit-1,L,R);
		for (int i = l + (1 << bit); i < l + (1 << (bit+1)); i++) ret[i] = ret[i - (1 << bit)];
	}
	else if (pos == L) {
		rec(l+(1<<bit),bit-1,L,R);
		for (int i = l; i < l + (1 << bit); i++) ret[i] = ret[i+(1<<bit)];
	} else {
		rec(l,bit-1,mx?pos:L,mx?R:pos-1);
		rec(l+(1<<bit),bit-1,mx?L:pos,mx?pos-1:R);
	}
}
vector<int> get (vector<int> &v, int m, bool _mx) { //m-bit numbers, get min/max xor with x forall x
	mx = _mx;
	if (v.empty()) return vector<int>(1<<m,mx?-1e9:1e9);
	cur = v; sort(cur.begin(),cur.end());
	rec(0,m-1,0,(int)cur.size()-1);
	for (int i = 0; i < (1 << m); i++) ret[i] ^= i;
	return vector<int>(ret,ret+(1<<m));
}
int main() {
    int n,k; scanf ("%d %d",&n,&k);
    vector<int> a(n), ret(1<<k,1e9);
    for (int i = 0; i < n; i++) scanf ("%d",&a[i]);
    vector<vector<int>> vs = {a};
    for (int bit = k-1; bit >= 0; bit--) { //first difference is bit
        vector<vector<int>> new_vs;
        vector<int> got(1 << (bit + 1),1e9);
        for (vector<int> &v : vs) {
            vector<int> v0, v1;
            for (int x : v) {
                if (x >> bit & 1) v1.push_back(x^(1<<bit));
                else v0.push_back(x);
            }
            sort(v0.begin(),v0.end());
            v0.erase(unique(v0.begin(),v0.end()),v0.end());
            sort(v1.begin(),v1.end());
            v1.erase(unique(v1.begin(),v1.end()),v1.end());
            vector<int> min_0 = get(v0,bit,0), min_1 = get(v1,bit,0), max_0 = get(v0,bit,1), max_1 = get(v1,bit,1);
            for (int mask = 0; mask < (1 << bit); mask++) {
				uin(got[mask | (1 << bit)],min_0[mask] - max_1[mask] + (1 << bit));
				uin(got[mask],min_1[mask] - max_0[mask] + (1 << bit));
			}
            if (!v0.empty()) new_vs.push_back(v0); 
            if (!v1.empty()) new_vs.push_back(v1);
        }
        for (int mask = 0; mask < (1 << k); mask++) {
			ret[mask] = min(ret[mask],got[mask&((1<<(bit+1))-1)]);
		}
        vs = new_vs;
    }
    for (int i = 0; i < (1 << k); i++) printf ("%d%c",ret[i]," \n"[i+1==(1<<k)]);
    return 0;
}
//0101010 | 0 | 101101