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
int a[400004],ans=0;
int num[400004];
int dp[400004],dp1[400004];
int main(){
	int n,I;cin>>n>>I;
	I*=8;
	I/=n;
	if (I>29){
		cout<<"0";return 0;
	}
	else I=1<<I;
	for (int i=0;i<n;i++) cin>>a[i];
	sort (a,a+n);
	int cnt=0;
	for (int i=0;i<n;i++){
		if (i==0 || a[i]!=a[i-1]) cnt++;
		num[cnt]++;
	}
	for (int i=1;i<=cnt;i++) dp[i]=dp[i-1]+num[i];
	for (int i=cnt;i>0;i--) dp1[i]=dp1[i+1]+num[i];
	if(cnt<=I){
		cout<<"0";return 0;
	}
	ans=1e9;
	for (int i=1;i<=cnt;i++){
		int p=dp[i];
		int o=0;
		if (i+I+1<=cnt) o=dp1[i+I+1];
		ans=min(p+o,ans);
	}
	cout<<ans;
}