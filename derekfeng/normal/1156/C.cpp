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
int n,z;
int a[200004];
bool check(int x){
	if (x>n/2) return false;
	for (int i=n,j=x;j>0;i--,j--)
		if (a[i]-a[j]<z) return false;
	return true;
}
int main(){
	cin>>n>>z;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort (a+1,a+n+1);
	int l=-1,r=n+1;
	while (r>l+1){
		int mid=(l+r+1)/2;
		if (check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
}