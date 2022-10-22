#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll A=257,MOD=1e9+7;
ll cnt[600004];
ll hashh(string s){
	ll q=0;
	for (ll i=0;i<s.size();i++) q=(q*A+s[i])%MOD;
	return q;
}
set <ll> st;
int main(){
	cnt[1]=1;
	for (ll i=2;i<=600004;i++) cnt[i]=cnt[i-1]*A%MOD;
	int n,m;
	cin>>n>>m;
	for (ll i=0;i<n;i++){
		string s;
		cin>>s;
		st.insert(hashh(s)); 
	}
	while (m--){
		string t;
		cin>>t;
		bool q=1;
		ll now=t.size();
		ll xzy=hashh(t);
		for (ll i=0;i<t.size() && q;i++)
			for (char c='a';c<='c' && q;c++){
				if (t[i]==c) continue;
				ll ln=(xzy+(c-t[i])*cnt[now-i]+3*MOD)%MOD;
				if (st.find(ln)!=st.end()){
					puts("YES");
					q=0;
				}
			}
		if (!q);
		else puts("NO");
	}
}