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
ll n,x,y,c;
ll rx,ry,cx,cy;
int trans(ll xx){
	return xx*(xx+1)/2;
} 
bool check(ll w){
	ll hig=min(w,rx)+min(w,ry)+1,wid=min(w,cx)+min(w,cy)+1;
	ll sum=hig*wid;
	ll u_l,u_r,d_l,d_r;
	if (w<=rx) u_l=max(0ll,min(w,cx));
	if (rx<w) u_l=max(0ll,min(w,cx)-(w-rx));
	if (w<=rx) u_r=max(0ll,min(w,cy));
	if (rx<w) u_r=max(0ll,min(w,cy)-(w-rx));
	if (w<=ry) d_l=max(0ll,min(w,cx));
	if (ry<w) d_l=max(0ll,min(w,cx)-(w-ry));
	if (w<=ry) d_r=max(0ll,min(w,cy));
	if (ry<w) d_r=max(0ll,min(w,cy)-(w-ry));
	return sum-trans(u_l)-trans(u_r)-trans(d_l)-trans(d_r)>=c;
}
int main(){
	cin>>n>>x>>y>>c;
	rx=x-1,ry=n-x,cx=y-1,cy=n-y;
	ll l=0,r=1e9;
	while (l<r){
		ll mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<r;
}