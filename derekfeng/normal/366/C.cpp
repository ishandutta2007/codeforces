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
using namespace std;
int n,a[103],b[103],k,ans=-1;
int dp[103][210000];
int main(){
	for (int i=0;i<103;i++)
		for (int j=0;j<210000;j++)
			dp[i][j]=-1;
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	dp[0][100000]=0;
	for (int i=1;i<=n;i++){
		for (int j=-100000;j<=100000;j++){
			int cnt=a[i]-k*b[i];
			if (dp[i-1][j+100000]!=-1) dp[i][j+100000]=dp[i-1][j+100000];
			if (dp[i-1][j+100000-cnt]!=-1){
				dp[i][j+100000]=max(dp[i][j+100000],dp[i-1][j+100000-cnt]+a[i]);
				if (j==0) ans=max(ans,dp[i][j+100000]);
			}
		}
	}
	cout<<ans;
}