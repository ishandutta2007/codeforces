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
int num[2][1003][1003],x[1003][1003];
int dp[2][1003][1003];
int cc=-1,rr=-1;
int main(){
	for (int i=0;i<1003;i++)
		for (int j=0;j<1003;j++)
			dp[0][i][j]=dp[1][i][j]=1e9;
	cin>>n;
	m=n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			cin>>x[i][j];
			if (x[i][j]==0) cc=i,rr=j;
			else{
				while (x[i][j]%2==0) x[i][j]/=2,num[0][i][j]++;
				while (x[i][j]%5==0) x[i][j]/=5,num[1][i][j]++;
			}
		}
	dp[0][0][1]=0;
	dp[1][0][1]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (x[i][j]==0) continue;
			dp[0][i][j]=min(dp[0][i][j],min(dp[0][i-1][j],dp[0][i][j-1])+num[0][i][j]);
			dp[1][i][j]=min(dp[1][i][j],min(dp[1][i-1][j],dp[1][i][j-1])+num[1][i][j]);
		}
	if (dp[0][n][m]>1 && dp[1][n][m]>1 && cc>-1 && rr>-1){
		cout<<"1\n";
		for (int i=1;i<rr;i++) cout<<"R";
		for (int i=1;i<n;i++) cout<<"D";
		for (int i=rr;i<m;i++) cout<<"R";
	}else{
		if (dp[0][n][m]<=dp[1][n][m]){
			cout<<dp[0][n][m]<<endl;
			int r=n,c=m;
			string ans;
			while (r!=1 || c!=1){
				if (x[r-1][c]!=0 && dp[0][r-1][c]==dp[0][r][c]-num[0][r][c]){
					r--;
					ans+="D";
					continue;
				}else{
					c--;
					ans+="R";
					continue;
				}
			}
			reverse (ans.begin(),ans.end());
			cout<<ans;
		}else{
			cout<<dp[1][n][m]<<endl;
			int r=n,c=m;
			string ans;
			while (r!=1 || c!=1){
				if (x[r-1][c]!=0 && dp[1][r-1][c]==dp[1][r][c]-num[1][r][c]){
					r--;
					ans+="D";
					continue;
				}else{
					c--;
					ans+="R";
					continue;
				}
			}
			reverse (ans.begin(),ans.end());
			cout<<ans;
		}
	}
}