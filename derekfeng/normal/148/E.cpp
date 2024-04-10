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
int n,m,d[103][103];
int tt,dp1[103][10003];
int a[103];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>tt;
		memset (a,0,sizeof(a));
		memset (d[i],-1,sizeof(d[i]));
		for (int j=1;j<=tt;j++) cin>>a[j];
		for (int j=2;j<=tt;j++) a[j]+=a[j-1];
		d[i][0]=0;
		for (int k=1;k<=tt;k++)
			for (int j=0;j<=k;j++){
				d[i][k]=max(d[i][k],a[j]+a[tt]-a[tt-(k-j)]);
		}
	}
	memset (dp1,-1,sizeof(dp1));
	dp1[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=100;j++)	
			for (int k=j;k<=m;k++)
				if (dp1[i-1][k-j]!=-1 && d[i][j]!=-1)
					dp1[i][k]=max(dp1[i][k],dp1[i-1][k-j]+d[i][j]);
	}
	int ans=0;
	for (int i=1;i<=m;i++)
		ans=max(dp1[n][i],ans);
	cout<<ans;
}