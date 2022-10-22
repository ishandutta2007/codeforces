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
int n,m,a,ans=0;
int b[100004],p[100004];
bool check(int x){
	int pl=a;
	for (int i=0;i<x;i++){
		if (p[i]>b[n-x+i]) pl-=(p[i]-b[n-x+i]);
		if (pl<0) return false;
	}
	return true;
}
int main(){
	cin>>n>>m>>a;
	for (int i=0;i<n;i++)
		cin>>b[i];
	for (int i=0;i<m;i++)
		cin>>p[i];
	sort (b,b+n);
	sort (p,p+m);
	int l,r,mid;
	l=0,r=min(n,m);
	while (l<=r){
		mid=(l+r)/2;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	for (int i=0;i<r;i++)
		ans+=p[i];
	ans-=a;
	cout<<r<<" "<<max(0,ans);
	return 0;
}