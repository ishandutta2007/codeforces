/*#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<string>
#include<bitset>
#include<algorithm>
#include<vector>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

int s1, s2, mx = 0;
set<pii> p1, p2;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	vi skill(n);
	F0R(i,n) {
		cin >> skill[i];
		mx = max(mx,skill[i]);
	}
	F0R(i,(n+1)/2) {
		p1.insert(mp(skill[i],i+1));
		s1 += skill[i];
	}
	FOR(i,(n+1)/2,n) {
		p2.insert(mp(skill[i],i+1));
		s2 += skill[i];
	}
	if (s1<s2) {
		swap(p1,p2);
		swap(s1,s2);
	}
	while(s1-s2>mx) {
		auto cmax = *prev(p1.end()), cmin = *p2.begin();
		s1 -= (cmax.f-cmin.f);
		s2 += (cmax.f-cmin.f);
		p1.erase(cmax);
		p1.insert(cmin);
		p2.erase(cmin);
		p2.insert(cmax);
	}
	cout << p1.size() << "\n";
	for (auto i: p1) cout << i.s << " ";
	cout << "\n";
	cout << p2.size() << "\n";
	for (auto i: p2) cout << i.s << " ";
}