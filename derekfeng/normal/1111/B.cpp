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
ll n,k,m;
ll a[100004];
double ans=0.0;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	a[0]=0;
	cin>>n>>k>>m;
	for (ll i=1;i<=n;i++) cin>>a[i];
	sort (a+1,a+n+1,cmp);
	for (ll i=2;i<=n;i++) a[i]+=a[i-1];
	for (ll i=0;i<n;i++){
		if (i>m) continue;
		ans=max(double(a[n-i]+min(m-i,k*(n-i)))/double(n-i),ans);
	}
	printf("%.12lf",ans); 
}