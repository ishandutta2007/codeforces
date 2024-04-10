#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef long long Int;
Int seg[1 << 20];
vector<Int> nums;
bool used[432000];
Int n, q, a[432000], b[432000], ans[432000];
Int ta[432000], tb[432000];
char c[432000];
Int val(int pos, int bottom = 0, int top = 1 << 19, int p = 1){
	if(seg[p] != -1)return seg[p];
	int mid = (bottom + top) / 2;
	if(pos < mid)return val(pos, bottom, mid, p * 2);
	else return val(pos, mid, top, p*2 + 1);
}

void setval(int l, int r, int val, int bottom = 0, int top = 1 << 19, int p = 1){
	if(r <= bottom || top <= l)return;
	if(l <= bottom && top <= r){
		seg[p] = val;
		return;
	}
	if(seg[p] != -1){
		seg[p*2+1] = seg[p*2] = seg[p];
		seg[p] = -1;
	}
	int mid= (bottom + top) / 2;
	setval(l, r, val, bottom, mid, p * 2);
	setval(l, r, val, mid, top, p * 2 + 1);
}

void solve(){
	fill(seg, seg + (1 << 20), -1);
	seg[1] = 0;
	fill(used, used + 432000, false);
	Int res = 0;
	set<int> u;
	set<int>::iterator it;
	u.insert(0);
	for(int i = 0;i < q;i++){
		a[i] = lower_bound(nums.begin(), nums.end(), ta[i]) - nums.begin();
		b[i] = tb[i];
	}
	for(int i = 0;i < q;i++){
		if(used[a[i]])continue;
		used[a[i]] = true;
		if(c[i] == 'U'){
			ans[i] = b[i] - val(a[i]);
		}
		if(c[i] == 'L'){
			it = u.lower_bound(a[i]);it--;
			if(val(*it) < b[i])
				setval(*it, a[i], b[i]);
		}                             
		u.insert(a[i]);
	}
}


int main(){
	cin >> n >> q;
	for(int i = 0;i < q;i++){
		cin >> ta[i] >> tb[i] >> c[i];
		nums.push_back(ta[i]);
		nums.push_back(tb[i]);
	} 
	nums.push_back(0);
	
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());	
	Int res = 0;
	solve();
	for(int i = 0;i < q;i++){
		swap(ta[i], tb[i]);
		if(c[i] == 'U')c[i] = 'L';
		else c[i] = 'U';
	}
	solve();
	for(int i = 0;i < q;i++){
		cout << ans[i] << endl;
	}
	return 0;
}