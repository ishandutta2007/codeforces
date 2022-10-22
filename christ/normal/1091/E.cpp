
// Problem : E. New Year and the Acquaintance Estimation
// Contest : Good Bye 2018
// URL : https://codeforces.com/contest/1091/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int check (vector<int> v, int add) {
	sort(v.begin(),v.end(),greater<int>());
	int pos = -1;
	for (int i = 0; i < v.size(); i++) if (v[i] == add) pos = i;
	vector<ll> psa;
	for (int i : v) psa.push_back((psa.empty()?0:psa.back())+i);
	int j = v.size()-1;
	for (int k = 1; k <= v.size(); k++) {
		while (j>=0&&k>v[j])--j;
		int to = max(k-1,j);
		ll hmm = k*1LL*(to-k+1)+psa[v.size()-1]-psa[to];
		if (psa[k-1] > k*1LL*(k-1)+hmm) {
			return pos<k?2:0;
		}
	}
	return 1;
}
int main () {
	int n; ll sum = 0;
	scanf ("%d",&n);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au), sum += au;
	int low = 0, high = n/2, mid, ans = -1;
	while (low <= high) {
		mid = (low+high)/2;
		a.push_back(mid*2+(sum&1));
	 	if (check(a,(mid*2)+(sum&1)) >= 1) high = (ans = mid) - 1;
		else low = mid + 1;
		a.pop_back();
	}
	a.push_back(ans*2+(sum&1));
	if (check(a,ans*2+(sum&1)) != 1) return !printf ("-1\n");
	a.pop_back();
	int l = ans;
	low = 0, high = n/2, ans = -1;
	while (low <= high) {
		mid = (low+high)/2;
		a.push_back(mid*2+(sum&1));
		if (check(a,mid*2+(sum&1)) <= 1) low = (ans = mid) + 1;
		else high = mid-1;
		a.pop_back();
	}
	for (int i = l*2+(sum&1); i <= ans*2+(sum&1); i+=2) printf ("%d ",i);
	return 0;
}