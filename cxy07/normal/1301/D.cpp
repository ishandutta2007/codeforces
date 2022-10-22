//Code By CXY
#include<bits/stdc++.h>
using namespace std;

int n,m,savk,k,lim;
vector<int> cnt;
vector<string> ans;

inline void print() {
	puts("YES");
	int len = cnt.size(),tmp;
	cout << len << endl;
	for(register int i = 0;i < len; ++i) {
		cout << cnt[i] << ' ' << ans[i] << endl;
		tmp += cnt[i] * ans[i].length();
	}
	return;
}

int main () {
	//freopen("in.in","r",stdin); 
	cin >> n >> m >> k; savk = k;
	if(k > 4 * n * m - 2 * n - 2 * m) {puts("NO"); return 0;}
	if(m == 1) {
		lim = n - 1;
		if(k <= lim) {
			cnt.push_back(k),ans.push_back("D");
			k = 0;
			print();
			return 0;
		}
		k -= lim;
		cnt.push_back(lim),ans.push_back("D");
		if(k <= lim) {
			cnt.push_back(k),ans.push_back("U");
			k = 0;
			print();
			return 0;
		} 
		k -= lim;
		cnt.push_back(lim),ans.push_back("U");
		if(!k) print();
		else puts("NO");
		return 0;
	}
	lim = m - 1; 
	for(register int i = 1;i <= n; ++i) {
		if(k <= lim) {
			cnt.push_back(k),ans.push_back("R");
			k = 0;
			break;
		}
		k -= lim;
		cnt.push_back(lim),ans.push_back("R");
		if(i < n && k <= lim * 3) {
			int tmp = k / 3,_;
			if(tmp) {
				cnt.push_back(tmp),ans.push_back("DUL");
			}
			_ = k - tmp * 3;
			if(_ == 1) cnt.push_back(1),ans.push_back("D");
			else if(_ == 2) cnt.push_back(1),ans.push_back("DU");
			k = 0;
			break;
		}
		if(i < n) {
			k -= lim * 3;
			cnt.push_back(lim),ans.push_back("DUL");
			cnt.push_back(1),ans.push_back("D");
			k--;
		} else {
			if(k <= lim) {
				cnt.push_back(k),ans.push_back("L");
				k = 0;
				break;
			} else {
				k -= lim;
				cnt.push_back(lim),ans.push_back("L");
			}
		}
		if(!k) break;
	}
	if(!k) {
		print();
		return 0;
	}
	if(k <= n - 1) {
		cnt.push_back(k),ans.push_back("U");
		print();
	} else puts("NO");
	return 0;
}