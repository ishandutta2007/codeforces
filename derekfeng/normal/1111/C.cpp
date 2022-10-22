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
ll n,k,A,B;
ll a[100004];
ll dfs(ll l,ll r){
	int ll=lower_bound(a,a+k,l)-a,rr=upper_bound(a,a+k,r)-a;
	int num=rr-ll; 
	if (num==0) return A;
	else{
		if (r-l==0) return B*num;
		return min(B*num*(r-l+1),dfs(l,(l+r)/2)+dfs((l+r)/2+1,r)); 
	}
}
int main(){
	cin>>n>>k>>A>>B;
	for (int i=0;i<k;i++)
		cin>>a[i];
	sort (a,a+k);
	cout<<dfs(1,(1ll<<n));
}