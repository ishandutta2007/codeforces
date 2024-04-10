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
ll a[100004];
ll n,m;
bool ok(ll x){
	ll al=0,bl=m;
	for (int i=1;i<=n;i++){
		ll t;
		al--;
		if (al<0) al++;
		if (i==x) return false;
		t=(a[i]-al+x-i-1)/(x-i);
		al=t*(x-i)+al-a[i];
		if (t>0) bl-=t;
		if (bl<0) return false; 
	}
	return true;
}
int main(){
	cin>>n>>m;
	for (ll i=1;i<=n;i++)
		cin>>a[i];
	while (n>0 && a[n]==0) n--;
	ll l=0,r=4e14;
	while (r>l){
		ll mid=(l+r)/2;
		if (ok(mid)) r=mid;
		else l=mid+1;
	}
	cout<<r;
	return 0;
}