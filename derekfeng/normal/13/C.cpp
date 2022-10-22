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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[5003];
ll a[5003];
vector <ll> v; 
int main(){
	for (int i=0;i<5003;i++)dp[i]=1e18;
	cin>>n;
	v.push_back(-1e18); 
	for (int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort (v.begin(),v.end());
	for (int i=1;i<=n;i++) dp[i]=max(0ll,a[1]-v[i]);
	for (int i=2;i<=n;i++){
		for (int j=1;j<=n;j++){ 
			ll x=v[j];
			if (x>a[i]) dp[j]=dp[j]+x-a[i];
			if (x<a[i]) dp[j]=dp[j]+a[i]-x;
			dp[j]=min(dp[j],dp[j-1]);
		}
	}
	ll ans=1e18;
	for (int i=1;i<=n;i++)
		ans=min(ans,dp[i]);
	cout<<ans;
}