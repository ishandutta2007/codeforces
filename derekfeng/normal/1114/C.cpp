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
ll n,b,ans=1e18;
map <ll,int> mp;
vector <ll> v,o;
ll cnt(ll nn){
	ll p=n,res=0;
	while (p){
		res+=p/nn;
		p/=nn;
	}
	return res;
}
int main(){
	cin>>n>>b;
	for (ll i=1;i*i<=b;i++)
		if (b%i==0){
			v.push_back(i);
			v.push_back(b/i);  
		}
	sort (v.begin(),v.end());
	for (int i=0;i<v.size();i++){
		while (v[i]!=1 && b%v[i]==0){
			mp[v[i]]++;
			b/=v[i];
		}
		if (!mp[v[i]]) continue;
		ll tt=cnt(v[i]);
		ans=min(ans,tt/mp[v[i]]);
	}
	cout<<ans;
}