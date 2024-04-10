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
int n,m;
int a[5003];
int dp[5003];
double xx233;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i]>>xx233;
	n++;
	a[n]=m+1;
	for (int i=1;i<=n;i++){
		dp[i]=0;
		for (int j=1;j<i;j++)
			if (a[j]<=a[i])
				dp[i]=max(dp[i],dp[j]);
		dp[i]++; 
	}
	cout<<n-dp[n];
}