//#include <bits/stdc++.h>

#include<vector>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<set>
#include<map>
#include<iomanip>
#include<string>
#include<iostream>
#include<math.h>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include <deque>
#include <queue>
using namespace std;
#define ll long long
vector <vector <ll> > g(50000);
vector <vector <ll> > gr(50000);
map <ll, ll> del;
vector <ll> used(50000);
//vector<pair <long long, pair<long long, long long> > > seg;
ll gcd(ll a, ll b){
	if(a == 0)
		return b;
	return gcd(b % a, a);
}
ll m;
ll gcd1 (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd1 (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
ll solve(ll a,ll b){
	ll x,y;
	ll d = gcd1(a,m,x,y);
	return ((x*(b/d) % m)+m)%m;
}

vector <ll> ans(50000);
vector <ll> pr(50000,-1);
void dfs(ll v){
	used[v] = 1;
	for(auto i = gr[v].begin(); i != gr[v].end(); i++)
		if(used[*i] == 0)
			dfs(*i);
	ll ns = 0;
	ns += g[v].size();
	ll mx = 0;
	ll pr1 = -1;
	for(auto i = gr[v].begin(); i != gr[v].end(); i++)
		if(mx <= ans[*i]){
		mx = max(mx, ans[*i]);
		pr1 = *i;
		}
	ans[v] = mx+ns;
	pr[v] = pr1;
}
int main(){
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	ll n;
	cin >> n >> m;
	set <ll> z;
	for(ll i = 0; i < n; i++){
		ll s;
		cin >> s;
		if(s == 0)
			z.insert(m);
		z.insert(s);
	}
	for(ll i = 1; i <= m; i++){
			if(z.find(i) == z.end()){
			ll gc = gcd(m, i);
			if(del.find(gc) == del.end()){
				del[gc] = del.size();
				g[del[gc]].push_back(i);
			}
			else
				g[del[gc]].push_back(i);
			}
	}
		for(auto i = del.begin(); i != del.end(); i++)
			for(auto j = del.begin(); j != del.end(); j++)
				if(i->second != j->second)
						if(i->first  % j->first == 0)
							gr[j->second].push_back(i->second);
	dfs(del[1]);
	ll s = del[1];
	vector <ll> ans1;
	while(s != -1){
		for(ll i = 0; i < g[s].size(); i++)
			ans1.push_back(g[s][i]);
		s = pr[s];
	}
	cout << ans1.size() << endl;
	for(ll i = 0;i<ans1.size();i++)
		cout << ((i ? solve(ans1[i-1],ans1[i]) : ans1[i])) % m <<' ';
    return 0;
}