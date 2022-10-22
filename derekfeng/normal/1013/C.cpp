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
long long a[200004];
int main(){
	int n;
	cin>>n;
	if (n==1){
		cout<<"0";
		return 0;
	}
	for (int i=0;i<2*n;i++)
		cin>>a[i];
	sort (a,a+2*n);
	long long ans=(a[n-1]-a[0])*(a[2*n-1]-a[n]);
	for (int i=1;i<=n;i++)
		ans=min(ans,(a[n-1+i]-a[i])*(a[2*n-1]-a[0]));
	cout<<ans;
	return 0;
}