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
ll n,m,k;
ll ovd(ll num){
	ll res=0;
	for (ll i=1;i<=min(n,num);i++) res+=min(num/i,m);
	return res;
}
int main(){
	cin>>n>>m>>k;
	ll l=0,r=n*m+1,mid;
	while (r>l+1){
		mid=(l+r)/2;
		if (ovd(mid)>=k) r=mid;
		else l=mid;
	}
	cout<<r;
}