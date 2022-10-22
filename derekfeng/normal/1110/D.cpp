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
int dp[1000005][3][6];
int num[1000005];
int main(){
	for (int i=0;i<1000005;i++)
		for (int j=0;j<3;j++)
			for (int k=0;k<6;k++)
				dp[i][j][k]=-1e9;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		int x;
		scanf ("%d",&x);
		num[x]++;
	}
	for (int i=0;i<=4;i++)
		if (num[1]>=i)
			dp[1][0][i]=(num[1]-i)/3;
	for (int i=2;i<=m;i++)
		for (int j=0;j<=min(2,num[i-1]);j++)
			for (int k=0;k<=min(4,num[i]);k++)
				for (int l=0;l<=2;l++)
					if (l+k<=num[i] && l+j<=num[i-1])
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][l][l+j]+(num[i]-l-k)/3+l); 
	cout<<dp[m][0][0];
}