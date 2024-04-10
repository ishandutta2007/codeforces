#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;
map<Int, long long> cnt;
Int num[108000];
Int gcd(Int a, Int b){
	if(a == 0)return b;
	return gcd(b % a, a);
}

void solve(Int l, Int r){
	if(r == l + 1){
		cnt[num[l]]++;
		return;
	}
	Int mid = (l + r) / 2;
	vector<P> le, ri;
	Int g = num[mid - 1];
	Int last = mid - 1;
	for(Int i = mid - 1;i >= l;i--){
		if(gcd(g, num[i]) != g){
			le.push_back(P(g, last - i));
			last = i;
			g = gcd(g, num[i]);
		}
	}
	le.push_back(P(g, last - l + 1));
	g = num[mid];
	last = mid;
	for(Int i = mid;i < r;i++){
		if(gcd(g, num[i]) != g){
			ri.push_back(P(g, i - last));
			last = i;
			g = gcd(g, num[i]);
		}
	}
	ri.push_back(P(g, r - last));
	for(Int i = 0;i < le.size();i++){
		for(Int j = 0;j < ri.size();j++){
			cnt[gcd(le[i].first, ri[j].first)] += le[i].second * ri[j].second;
		}
	}
	solve(l, mid);
	solve(mid, r);
}

int main(){
	Int n, x, q;
	cin >> n;
	for(Int i = 0;i < n;i++){
		cin >> num[i];
	}
	solve(0, n);
	cin >> q;
	while(q--){
		cin >> x;
		cout << cnt[x] << endl;
	}
	return 0;
}