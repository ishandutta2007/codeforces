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
using namespace std;
int a[3003],b[3003],c[3003],n,dp[3003][2];
int main(){
	cin>>n;
	for (int i=0;i<n;i++) scanf ("%d",&a[i]);
	for (int i=0;i<n;i++) scanf ("%d",&b[i]);
	for (int i=0;i<n;i++) scanf ("%d",&c[i]);
	dp[0][0]=a[0];
	dp[0][1]=a[0];
	for (int i=1;i<n;i++){
		dp[i][0]=max(dp[i-1][0]-a[i-1]+b[i-1]+a[i],(i==1)?dp[i-1][0]-a[i-1]+b[i-1]+a[i]:dp[i-1][1]-b[i-1]+c[i-1]+a[i]);
		dp[i][1]=max(dp[i-1][0],dp[i-1][1])+b[i];
	}
	cout<<max(dp[n-1][0],dp[n-1][1]);
}