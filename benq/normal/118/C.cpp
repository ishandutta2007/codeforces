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

pair<int,string> best;
int n,k; 
string s;

pair<int,string> get(int num) {
	vector<pair<int,pii>> x;
	string news = s;
	int need = k, co = 0;
	F0R(i,n) if (s[i] != (num+'0')) {
		int c = int(s[i]-'0');
		auto cur = mp(abs(c-num),mp(-c,0));
		if (c>num) cur.s.s = i;
		else cur.s.s = -i;
		x.pb(cur);
	}
	else need--;
	sort(x.begin(),x.end());
	if (need) F0R(i,need) {
		news[abs(x[i].s.s)] = char('0'+num);
		co += x[i].f;
	}
	return mp(co,news);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> s;
	best = mp(MOD,"");
	F0R(i,10) best = min(best,get(i));
	cout << best.f << "\n" << best.s;
}