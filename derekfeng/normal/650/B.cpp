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
int d[500004],n,a,b,T;
bool check(int l,int r) {
	int ww=d[n]-d[r-1];
	ww+=d[l];
	ww+=min((l-1)*a,(n-r+1)*a);
	return ww<=T;
}
int main() {
	int ans=0;
	string s;
	cin>>n>>a>>b>>T>>s;
	for (int i=1; i<=n; i++) {
		if (i>1) d[i]=d[i-1]+a;
		if (s[i-1]=='w') d[i]+=b;
		d[i]++;
	}
	for (int i=1; i<=n; i++){
		if (d[i]>T){
			ans=i-1;
			break;
		}
		if (i==n){
			cout<<n;
			return 0;
		}
	}
	for (int i=n; i>=2; i--) {
		int l,r,mid,res=0;
		l=1,r=i-1;
		while (r>=l) {
			mid=(l+r)/2;
			if (check(mid,i)) {
				res=max(res,mid+n-i+1);
				l=mid+1;
			} else r=mid-1;
		}
		ans=max(res,ans);
	}
	cout<<ans;
	return 0;
}