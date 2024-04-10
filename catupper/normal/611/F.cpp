#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define left left___
#define right right___
#define ws ws___

typedef long long Int;
vector<Int> nums;
#define INF (1LL << 62)
#define MOD 1000000007
Int n, h, w;
string str;
Int hs[500001], ws[500001];
Int res;
Int up[500001], down[500001], left[500001], right[500001];


int main(){
	cin >> n >> h >> w;
	cin >> str;
	
	fill(up, up + 500001, INF);
	fill(down, down + 500001, INF);
	fill(left, left + 500001, INF);
	fill(right, right + 500001, INF);
	
	Int x = 0, y = 0;
	
	for(Int i = 0;i < n;i++){
		if(str[i] == 'U')x++;
		if(str[i] == 'R')y++;
		if(str[i] == 'D')x--;
		if(str[i] == 'L')y--;
		if(x >= 0)up[x] = min(up[x], i+1);
		if(x <= 0)down[-x] = min(down[-x], i+1);
		if(y >= 0)right[y] = min(right[y], i+1);
		if(y <= 0)left[-y] = min(left[-y], i+1);
	}
	for(Int i = 0;i <= 500000;i++){
		if(x >= 0 && i + x <= 500000)up[i+x] = min(up[i+x], up[i]+n);
		if(x >= 0 && x - i >= 0)up[x-i] = min(up[x-i], down[i]+n);
		
		if(x <= 0 && i - x <= 500000)down[i-x] = min(down[i-x], down[i]+n);
		if(x <= 0 && -x - i >= 0)down[-x-i] = min(down[-x-i], up[i]+n);
		
		if(y >= 0 && i + y <= 500000)right[i+y] = min(right[i+y], right[i]+n);
		if(y >= 0 && y - i >= 0)right[y-i] = min(right[y-i], left[i]+n);
		
		if(y <= 0 && i - y <= 500000)left[i-y] = min(left[i-y], left[i]+n);
		if(y <= 0 && -y - i >= 0)left[-y-i] = min(left[-y-i], right[i]+n);
	}
	
	for(Int i = 0;i < h;i++){
		hs[i] = min(up[i+1], down[h-i]);   
//		cout << hs[i] << " " << "R" <<  endl;
		nums.push_back(hs[i]);
	}	
	sort(hs, hs+h);
	for(Int i = 0;i < w;i++){
		ws[i] = min(right[i+1], left[w-i]);
//		cout << ws[i] << endl;
		nums.push_back(ws[i]);
	}
	sort(ws, ws + w);
	
	if(hs[h-1] == INF && ws[w-1] == INF){
		cout << -1 << endl;
		return 0;
	}
	
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	
	for(Int i = 0;i < nums.size();i++){
		Int val = nums[i];
		if(val == INF)continue;
		Int ll = upper_bound(hs, hs+h, val) - lower_bound(hs, hs+h, val);
		Int rr = upper_bound(ws, ws+w, val) - lower_bound(ws, ws+w, val);
		Int lo = hs + h - lower_bound(hs, hs + h, val);
		Int ro = ws + w - lower_bound(ws, ws + w, val);
//		cout << val << " " << ll << " " << rr << " " << lo << " " << ro << endl;
		res += (val % MOD) * (ll*ro + rr*lo -ll*rr) %MOD;
		res %= MOD;
	}
	if(res < 0)res += MOD;
	cout << res << endl;
	return 0;
		
}