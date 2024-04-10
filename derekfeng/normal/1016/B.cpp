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
typedef pair<ll,ll> pll;
const ll MOD=1e9+7,A=257,B=2011;
int n,m,q;
bool ok[1003];
pll hashh(string s) {
	ll p1=0,p2=0;
	for (int i=0; i<s.size(); i++) p1=(p1*A+s[i])%MOD,p2=(p2*B+s[i])%MOD;
	return pll(p1,p2);
}
int main() {
	int l=0;
	string s,t;
	cin>>n>>m>>q>>s>>t;
	pll num=hashh(t);
	for (int i=0; i<=n-m; i++){
		pll a=hashh(s.substr(i,m));
		if (a.first==num.first && a.second==num.second) ok[i]=1;
	}
	while (q--) {
		int l,r,ans=0;
		cin>>l>>r;
		l--,r--;
		for (int i=l; i<=r-m+1; i++)
			if (ok[i]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}