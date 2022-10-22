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
int n,m,k;
int a[300004];
long long dp[300004][10],ans=0;
int main(){
	for (int i=0;i<300004;i++)for(int j=0;j<10;j++)dp[i][j]=-1e16;
	cin>>n>>m>>k;
	for (int i=0;i<n;i++)cin>>a[i];
	dp[0][0]=0;
	if(m!=1)dp[0][1]=a[0]-k;
	else dp[0][0]=max(a[0]-k,0);
	for (int i=0;i<m;i++)ans=max(ans,dp[0][i]);
	for (int i=1;i<n;i++){
		if (m!=1) dp[i][0]=max(0ll,dp[i-1][m-1]+a[i]);
		else dp[i][0]=max(0ll,dp[i-1][m-1]+a[i]-k);
		for(int j=1;j<m;j++){
			if (j==1) dp[i][j]=dp[i-1][j-1]+a[i]-k;
			else dp[i][j]=dp[i-1][j-1]+a[i]; 
		}
		for (int j=0;j<m;j++)ans=max(ans,dp[i][j]);
	}
	cout<<ans;
}